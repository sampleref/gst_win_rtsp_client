#include "StartForm.h"
#include <gst/gst.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//gstplayer is your project name
	gstplayer::StartForm form;
	Application::Run(%form);
}

int impl_funcs::playRtspUrlVideo(std::string rtsp_url) {
	GstElement *pipeline;
	GstBus *bus;
	GstMessage *msg;

	/* Initialize GStreamer */
	gst_init(NULL, NULL);

	addLogTextLine("Starting Pipeline ... ");

	/* Build the pipeline */
	const std::string pipeline_str = "rtspsrc location=" + rtsp_url + " ! rtph264depay ! avdec_h264 ! autovideosink ";
	pipeline = gst_parse_launch(pipeline_str.c_str(), NULL);

	addLogTextLine("Set Pipeline PLAYING ");
	/* Start playing */
	gst_element_set_state(pipeline, GST_STATE_PLAYING);

	/* Wait until error or EOS */
	bus = gst_element_get_bus(pipeline);
	msg =
		gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GstMessageType(
			GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

	/* Free resources */
	if (msg != NULL)
		gst_message_unref(msg);
	gst_object_unref(bus);
	gst_element_set_state(pipeline, GST_STATE_NULL);
	gst_object_unref(pipeline);
	return 0;
}

void impl_funcs::addLogTextLine(std::string text) {
	gstplayer::StartForm::startFormInstance->log_text->AppendText(gcnew String(text.c_str()));
	gstplayer::StartForm::startFormInstance->log_text->AppendText("\r\n");
}