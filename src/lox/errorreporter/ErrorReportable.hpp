#pragma once

#include "IErrorReporter.hpp"

class ErrorReportable {
   public:
    virtual ~ErrorReportable();
   protected:
    ErrorReportable(const IErrorReporter& error_reporter);
    const IErrorReporter& error_reporter;
};