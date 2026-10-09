#pragma once
#include <cstdio>

// Log by importance
enum class LogLevel{
    Info,
    Warning,
    Error
};

inline void logMessage(LogLevel level, const char* file, int line, const char* msg){
    const char* tag = level == LogLevel::Error ? "ERROR" : level == LogLevel::Warning ? "WARNING" : "INFO";
    std::fprintf(level == LogLevel::Error ? stderr : stdout, "[%s] %s:$d: %s\n", tag, file, line, msg);
}

#define LOG_INFO(msg) logMessage(LogLevel::Info, __FILE__, __LINE__, msg)
#define LOG_WARNING(msg) logMessage(LogLevel::Warning, __FILE__, __LINE__, msg)
#define LOG_ERROR(msg) logMessage(LogLevel::Error, __FILE__, __LINE__, msg)