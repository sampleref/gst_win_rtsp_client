# gst_win_rtsp_client

Windows based Desktop Application to play RTSP stream using GStreamer
=======================================================================  
Point the System/Environment Variable as 

GSTREAMER_1_0_ROOT_X86_64 = C:\gstreamer\1.0\x86_64\
=======================================================================  
For RUNTIME only(For clients using exe) 
set as per instructions at https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c

Add to Path %GSTREAMER_1_0_ROOT_X86_64%bin
=======================================================================
For Secure RTSP Client on Windows Set:
As suggested at https://gitlab.freedesktop.org/gstreamer/cerbero/issues/190
GIO_MODULE_DIR=C:\gstreamer\1.0\x86_64\lib\gio\modules