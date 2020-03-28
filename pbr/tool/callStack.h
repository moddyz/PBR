#pragma once

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// Print the call stack.
void CallStackPrint();

/// Used in PBR_ASSERT to print the call stack when an expression fails to evaluate.
///
/// \param i_expression the expression which evaluated to false.
PBR_API
void CallStackPrint( const char* i_expression );

/// Used in PBR_ASSERT_MSG to print the call stack when an expression fails to evaluate.
///
/// \param i_expression the expression which evaluated to false.
/// \param i_format formatted cstring.
PBR_API
void CallStackPrint( const char* i_expression, const char* i_format, ... );

PBR_NAMESPACE_END
