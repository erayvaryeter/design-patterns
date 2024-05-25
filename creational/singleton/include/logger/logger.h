#pragma once

#include <string>
#include <iostream>

#define LOGGER_SET_SEVERITY(X) Logger::GetInstance().SetSeverityLevel(X)
#define LOG(X, Y) Logger::GetInstance().PrintLog(X, Y)

class Logger {
public:
    enum SeverityLevel : uint8_t {
        ERROR = 0,
        WARNING = 1,
        INFO = 2,
        DEBUG = 3
    };

    static Logger& GetInstance();
    void SetSeverityLevel(SeverityLevel logLevel);
    SeverityLevel GetSeverityLevel();
    void PrintLog(SeverityLevel level, const std::string& log);

private:
    Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    SeverityLevel m_severityLevel;
};