#pragma once

#include "IErrorReporter.hpp"

class ErrorReportable {
   public:
    virtual ~ErrorReportable() = 0;
   protected:
    IErrorReporter error_reporter;
};