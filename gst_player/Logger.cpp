#include "Logger.hpp"
using namespace System;

void loggerImpl::addLogTextLine(std::string text){
	gstplayer::StartForm::startFormInstance->log_text->AppendText(gcnew String(text.c_str()));
	gstplayer::StartForm::startFormInstance->log_text->AppendText("\r\n");
}