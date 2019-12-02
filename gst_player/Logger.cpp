#include "Logger.hpp"
using namespace System;

void loggerImpl::addLogTextLine(std::string text){
	gstplayer::StartForm::startFormInstance->log_text->AppendText(gcnew String(text.c_str()));
	gstplayer::StartForm::startFormInstance->log_text->AppendText("\r\n");
}

void ConsoleWriter::Write(System::String^ value)
{
	loggerImpl::addLogTextLine(msclr::interop::marshal_as<std::string>(value));
	this->Flush();
}

void ConsoleWriter::WriteLine(System::String^ value)
{
	loggerImpl::addLogTextLine(msclr::interop::marshal_as<std::string>(value));
	this->Flush();
}