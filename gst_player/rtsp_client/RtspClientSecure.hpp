#pragma once
#include <string>

namespace rtspClient {
	int playRtspUrl(std::string rtspUrl, bool secure, std::string username, std::string passworrd, std::string certPath, std::string keyPath);
}
