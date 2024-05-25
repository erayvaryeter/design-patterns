#include "logger/logger.h"

Logger& Logger::GetInstance()
{
    static Logger instance;
    return instance;
}

void Logger::SetSeverityLevel(Logger::SeverityLevel logLevel)
{
    m_severityLevel = logLevel;
}

Logger::SeverityLevel Logger::GetSeverityLevel()
{
    return m_severityLevel;
}

void Logger::PrintLog(Logger::SeverityLevel level, const std::string& log)
{
    auto GetSeverityString = [](Logger::SeverityLevel level) -> std::string {
        int logLevel = static_cast<int>(level);
        std::string retVal = "";
        switch (logLevel) {
        case 0: retVal = "ERROR - "; break;
        case 1: retVal = "WARNING - "; break;
        case 2: retVal = "INFO - "; break;
        case 3: retVal = "DEBUG - "; break;
        default: break;
        }
        return retVal;
    };

    if (static_cast<uint8_t>(level) <= static_cast<uint8_t>(m_severityLevel)) {
        std::cout << GetSeverityString(level) << log << std::endl;
    }
}

Logger::Logger() : m_severityLevel(Logger::ERROR) {}