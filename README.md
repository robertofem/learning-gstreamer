Learning GStreamer
==================

Test projects to test the capacities of GStreamer

Install GStreamer
-----------------

https://gstreamer.freedesktop.org/documentation/installing/on-linux.html?gi-language=c

Basic Tutorials
---------------

Use the following commands to compile the examples in basic_tutorials folder:

```
gcc basic-tutorial-1.c -o basic-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`
gcc basic-tutorial-2.c -o basic-tutorial-2 `pkg-config --cflags --libs gstreamer-1.0`
gcc basic-tutorial-3.c -o basic-tutorial-3 `pkg-config --cflags --libs gstreamer-1.0`
gcc basic-tutorial-4.c -o basic-tutorial-4 `pkg-config --cflags --libs gstreamer-1.0`
gcc basic-tutorial-5.c -o basic-tutorial-5 `pkg-config --cflags --libs gstreamer-video-1.0 gtk+-3.0 gstreamer-1.0`
gcc basic-tutorial-6.c -o basic-tutorial-6 `pkg-config --cflags --libs gstreamer-1.0`
gcc basic-tutorial-7.c -o basic-tutorial-7 `pkg-config --cflags --libs gstreamer-1.0`
gcc basic-tutorial-8.c -o basic-tutorial-8 `pkg-config --cflags --libs gstreamer-1.0 gstreamer-audio-1.0`
gcc basic-tutorial-9.c -o basic-tutorial-9 `pkg-config --cflags --libs gstreamer-1.0 gstreamer-pbutils-1.0`
```

Aravis Tests
------------

Tests mixing GStreamer and Aravis.

Install Aravis 0.8 with GStreamer support:

```
meson build
cd build
meson configure -Dgst-plugin='enabled'
ninja
ninja install
```

Add folder where Aravis 0.8 plugin for GStreamer is installed:

```
export GST_PLUGIN_PATH=/usr/local/lib/x86_64-linux-gnu/
```

If needed add the folder of the aravis library file:

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/x86_64-linux-gnu/
```

Finally compile with:

```
gcc arv2screen.c -o arv2screen `pkg-config --cflags --libs gstreamer-1.0`
```
