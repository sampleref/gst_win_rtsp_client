# gst_win_rtsp_client

Windows based Desktop Application to play RTSP stream using GStreamer
=======================================================================  

Development Environment:    

Install GStreamer Development and Runtime Libraries as mentioned https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c

Development package https://gstreamer.freedesktop.org/data/pkg/windows/1.16.1/gstreamer-1.0-devel-msvc-x86_64-1.16.1.msi  
Runtime package https://gstreamer.freedesktop.org/data/pkg/windows/1.16.1/gstreamer-1.0-msvc-x86_64-1.16.1.msi  

Point the System/Environment Variable as GSTREAMER_1_0_ROOT_X86_64 = C:\gstreamer\1.0\x86_64\

And Open this solution with Visual Studio 2017 or higher version

For Secure RTSP Client on Windows Set System/Environment Variable as:
GIO_MODULE_DIR=C:\gstreamer\1.0\x86_64\lib\gio\modules
As suggested at https://gitlab.freedesktop.org/gstreamer/cerbero/issues/190

To Build Application as exe only or with console in background for logs use configuration:
Project>Project Properties>Linker>System and in the right pane, set SubSystems option to 
Console(/SUBSYSTEM:WINDOWS) or Console(/SUBSYSTEM:CONSOLE) respectively

=======================================================================  


RUNTIME Environment(For clients using exe):

Install only Runtime package https://gstreamer.freedesktop.org/data/pkg/windows/1.16.1/gstreamer-1.0-msvc-x86_64-1.16.1.msi     
set as per instructions at https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c    

Point the System/Environment Variable as GSTREAMER_1_0_ROOT_X86_64 = C:\gstreamer\1.0\x86_64\

Add to Path %PATH%;%GSTREAMER_1_0_ROOT_X86_64%bin

Also VCRUNTIME latest for 2017 and above if not already installed
https://support.microsoft.com/en-in/help/2977003/the-latest-supported-visual-c-downloads
https://aka.ms/vs/16/release/vc_redist.x64.exe

=======================================================================

