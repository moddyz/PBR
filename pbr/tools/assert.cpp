#include <cxxabi.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

namespace pbr
{
void AssertHandler( const char* i_expression )
{
    printf( "<PBR_ASSERT failed for expression: %s>\n", i_expression );

    constexpr size_t c_maxStackDepth = 16;
    void*            backtracePtrs[ c_maxStackDepth ];
    int              stackDepth = backtrace( backtracePtrs, c_maxStackDepth );
    for ( int stackIndex = 0; stackIndex < stackDepth; ++stackIndex )
    {
        Dl_info dynamicLinkInfo;
        if ( !dladdr( backtracePtrs[ stackIndex ], &dynamicLinkInfo ) )
        {
            continue;
        }

        const char* symbolName;
        symbolName = dynamicLinkInfo.dli_sname;

        int   status;
        char* demangledSymbol;
        demangledSymbol = abi::__cxa_demangle( symbolName, NULL, 0, &status );
        if ( status == 0 && demangledSymbol )
        {
            symbolName = demangledSymbol;
        }

        printf( "\t%s, %s\n", dynamicLinkInfo.dli_fname, symbolName );

        if ( demangledSymbol )
        {
            free( demangledSymbol );
        }
    }
}

} // namespace pbr
