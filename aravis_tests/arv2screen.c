#include <gst/gst.h>

int main(int argc, char *argv[]) {
  GstElement *pipeline, *arvsrc, *vidqueue, *vidconvert, *vidsink;
  GstBus *bus;
  GstMessage *msg;
  gboolean terminate = FALSE;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Create the elements */
  arvsrc = gst_element_factory_make ("aravissrc", "video_source");
  vidqueue = gst_element_factory_make ("queue", "video_queue");
  vidconvert = gst_element_factory_make ("videoconvert", "video_convert");
  vidsink = gst_element_factory_make ("xvimagesink", "video_sink");

  /* Create the empty pipeline */
  pipeline = gst_pipeline_new ("arv2screen-pipeline");

  if (!pipeline || !arvsrc || !vidqueue || !vidconvert || !vidsink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

  /* Configure elements */
  //g_object_set (arvsrc, "exposure-auto", 1, NULL);

  /* Link elements  */
  gst_bin_add_many (GST_BIN (pipeline), arvsrc, vidqueue, vidconvert, vidsink, NULL);
  if (gst_element_link_many (arvsrc, vidqueue, NULL) != TRUE ||
      gst_element_link_many (vidqueue, vidconvert, NULL) != TRUE ||
      gst_element_link_many (vidconvert, vidsink, NULL) != TRUE ) {
    g_printerr ("Elements could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }

  /* Start playing the pipeline */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);

  do {
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
        GST_MESSAGE_STATE_CHANGED | GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    /* Parse message */
    if (msg != NULL) {
      GError *err;
      gchar *debug_info;

      switch (GST_MESSAGE_TYPE (msg)) {
        case GST_MESSAGE_ERROR:
          gst_message_parse_error (msg, &err, &debug_info);
          g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), err->message);
          g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
          g_clear_error (&err);
          g_free (debug_info);
          terminate = TRUE;
          break;
        case GST_MESSAGE_EOS:
          g_print ("End-Of-Stream reached.\n");
          terminate = TRUE;
          break;
        case GST_MESSAGE_STATE_CHANGED:
          /* We are only interested in state-changed messages from the pipeline */
          if (GST_MESSAGE_SRC (msg) == GST_OBJECT (pipeline)) {
            GstState old_state, new_state, pending_state;
            gst_message_parse_state_changed (msg, &old_state, &new_state, &pending_state);
            g_print ("Pipeline state changed from %s to %s:\n",
                gst_element_state_get_name (old_state), gst_element_state_get_name (new_state));
          }
          break;
        default:
          /* We should not reach here */
          g_printerr ("Unexpected message received.\n");
          break;
      }
      gst_message_unref (msg);
    }
  } while (!terminate);

  /* Free resources */
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;

}
