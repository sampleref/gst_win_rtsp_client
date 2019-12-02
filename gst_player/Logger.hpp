#pragma once

#ifndef _logger_impl_hpp_
#define _logger_impl_hpp_

#include "StartForm.h"

namespace loggerImpl {
	void addLogTextLine(std::string text);
}

public ref class ConsoleWriter : public System::IO::TextWriter {

public:
	virtual property System::Text::Encoding^ Encoding
	{
		System::Text::Encoding^ get() override { return System::Text::Encoding::UTF8; }
	}
	void Write(System::String^ value) override;
	void WriteLine(System::String^ value) override;
};
#endif