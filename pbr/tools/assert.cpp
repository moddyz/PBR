#include <execinfo.h>
#include <stdio.h>
#include <cstdlib>

namespace pbr
{
void AssertHandler()
{
    void*  callstack[ 128 ];
    int    numFrames, frames = backtrace( callstack, 128 );
    char** strs = backtrace_symbols( callstack, frames );
    for ( numFrames = 0; numFrames < frames; ++numFrames )
    {
        printf( "%s\n", strs[ numFrames ] );
    }
    free( strs );
}

} // namespace pbr
