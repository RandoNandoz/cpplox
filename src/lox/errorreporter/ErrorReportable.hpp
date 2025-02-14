#pragma once

#include "IErrorReporter.hpp"

class ErrorReportable {
   public:
    virtual ~ErrorReportable();
   protected:
    ErrorReportable(IErrorReporter& error_reporter);
    IErrorReporter& error_reporter;
};