#include <pbr/api.h>
#include <pbr/tools/log.h>

#include <sstream>
#include <stdarg.h>

#define BACKWARD_HAS_DW 1

#include <backward/backward.hpp>

PBR_NAMESPACE_BEGIN

void TlCallStackPrint()
{
    backward::StackTrace stackTrace;
    stackTrace.load_here( 32 );
    backward::Printer printer;
    printer.object     = true;
    printer.color_mode = backward::ColorMode::always;
    printer.address    = true;
    printer.print( stackTrace, stderr );
}

void TlCallStackPrint( const char* i_expression )
{
    PBR_LOG_ERROR( "PBR_ASSERT failed for expression: %s\n", "foo" );
    TlCallStackPrint();
}

void TlCallStackPrint( const char* i_expression, const char* i_format, ... )
{
    std::stringstream ss;
    ss << "PBR_ASSERT failed for expression: " << i_expression << ", " << i_format << "\n";

    va_list args;
    va_start( args, i_format );
    PBR_LOG_ERROR( ss.str().c_str(), args );
    va_end( args );

    TlCallStackPrint();
}

PBR_NAMESPACE_END
