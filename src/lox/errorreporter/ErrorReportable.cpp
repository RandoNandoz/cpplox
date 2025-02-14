#include "ErrorReportable.hpp"

#include "IErrorReporter.hpp"

ErrorReportable::ErrorReportable(IErrorReporter& error_reporter) : error_reporter(error_reporter) {}

ErrorReportable::~ErrorReportable() = default;