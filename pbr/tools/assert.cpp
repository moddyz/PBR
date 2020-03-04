#define BACKWARD_HAS_DW 1

#include "thirdparty/backward.hpp"

namespace pbr
{
void AssertHandler( const char* i_expression )
{
    printf( "<PBR_ASSERT failed for expression: %s>\n", i_expression );
    backward::StackTrace stackTrace;
    stackTrace.load_here( 32 );
    backward::Printer printer;
    printer.object     = true;
    printer.color_mode = backward::ColorMode::always;
    printer.address    = true;
    printer.print( stackTrace, stderr );
}

} // namespace pbr
