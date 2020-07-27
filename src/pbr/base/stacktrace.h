#pragma once

#include <pbr/pbr.h>

PBR_NS_OPEN

/// Print the stack trace.
void PrintStacktrace();

/// Used in PBR_ASSERT to print the stacktrace when an expression fails to evaluate.
///
/// \param i_expression the expression which evaluated to false.
PBR_API
void PrintStacktrace( const char* i_expression );

/// Used in PBR_ASSERT_MSG to print the stacktrace when an expression fails to evaluate.
///
/// \param i_expression the expression which evaluated to false.
/// \param i_format formatted cstring.
PBR_API
void PrintStacktrace( const char* i_expression, const char* i_format, ... );

PBR_NS_CLOSE
