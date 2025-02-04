#include "ErrorReportable.hpp"

#include "IErrorReporter.hpp"

ErrorReportable::ErrorReportable(const IErrorReporter& error_reporter) : error_reporter(error_reporter) {}

ErrorReportable::~ErrorReportable() = default;