#pragma once
/**
    Pure virtual class for error reporting
 */
#include <string>
class IErrorReporter {
    public:
        virtual ~IErrorReporter();
        virtual void log_error(const int line, const std::string& message) = 0;
        virtual void report(const int line, const std::string& where, const std::string& message) = 0;
};