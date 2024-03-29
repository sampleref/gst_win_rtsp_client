#include "StartForm.h"
#include "Logger.hpp"
#include "rtsp_client/RtspClientSecure.hpp"
#include <gst/gst.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	/*Default GStreamer Log Level*/
	Environment::SetEnvironmentVariable("GST_DEBUG", "3");

	/* To Enable Custom Console Writer */
	/*
	ConsoleWriter^ consoleWriter = gcnew ConsoleWriter();
	Console::SetOut(consoleWriter);
	Console::SetError(consoleWriter);
	*/

	//gstplayer is your project name
	gstplayer::StartForm form;
	Application::Run(%form);
}

int playSimpleRtspUrl(std::string rtsp_url);

int impl_funcs::playRtspUrlVideo(std::string rtsp_url, bool secure, std::string username, std::string password, std::string cert, std::string key) {
	return rtspClient::playRtspUrl(rtsp_url, secure, username, password, cert, key);
	//return playSimpleRtspUrl(rtsp_url);
}

void impl_funcs::setEnvironmentVariable(System::String^ variable, System::String^ value) {
	Environment::SetEnvironmentVariable(variable, value);
	std::string var_name = msclr::interop::marshal_as<std::string>(variable);
	if (var_name.compare("GST_DEBUG") == 0) {
		gst_debug_set_threshold_from_string(msclr::interop::marshal_as<std::string>(value).c_str(), TRUE);
	}
	MessageBox::Show("Environment variable set successfully", "Done", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
}

int playSimpleRtspUrl(std::string rtsp_url) {
	GstElement *pipeline;
	GstBus *bus;
	GstMessage *msg;

	/* Initialize GStreamer */
	gst_init(NULL, NULL);

	loggerImpl::addLogTextLine("Starting Pipeline ... ");

	/* Build the pipeline */
	const std::string pipeline_str = "rtspsrc location=" + rtsp_url + " ! rtph264depay ! avdec_h264 ! autovideosink ";
	pipeline = gst_parse_launch(pipeline_str.c_str(), NULL);

	loggerImpl::addLogTextLine("Set Pipeline PLAYING ");
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