#include <stddef.h>
#include <stdio.h>

#include <pbr/tools/profile.h>

void testProfileFunction( int foo = 0 )
{
    PBR_PROFILE_FUNCTION();
    size_t k = 0;
    for ( size_t i = 0; i < 1000000000; ++i )
    {
        k += i;
    }

    printf( "%lu\n", k );
    {
        PBR_PROFILE_FUNCTION();
    }

    {
        PBR_PROFILE_FUNCTION();
    }
}

void testProfile()
{
    PBR_PROFILE( "profile" );
    size_t k = 0;
    for ( size_t i = 0; i < 1000000; ++i )
    {
        k += i;
    }
}

void foo()
{
    size_t k = 0;
    for ( size_t i = 0; i < 1000000; ++i )
    {
        k += i;
    }
}

int main()
{
    foo();
    testProfileFunction();
    testProfile();
}
