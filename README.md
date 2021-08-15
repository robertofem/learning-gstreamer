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

```
gcc arv2screen.c -o arv2screen `pkg-config --cflags --libs gstreamer-1.0`
```
