#include <logger/logger.h>

int main()
{
	auto PrintLogMessages = []() {
		LOG(Logger::ERROR, "Error Log");
		LOG(Logger::WARNING, "Warning Log");
		LOG(Logger::INFO, "Info Log");
		LOG(Logger::DEBUG, "Debug Log");
	};

	LOGGER_SET_SEVERITY(Logger::ERROR);
	PrintLogMessages();

	LOGGER_SET_SEVERITY(Logger::WARNING);
	PrintLogMessages();

	LOGGER_SET_SEVERITY(Logger::INFO);
	PrintLogMessages();

	LOGGER_SET_SEVERITY(Logger::DEBUG);
	PrintLogMessages();

	return 0;
}