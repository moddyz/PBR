#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <stddef.h>
#include <stdio.h>
#include <thread>
#include <vector>

#include <pbr/tool/profile.h>

void testProfileFunction()
{
    PBR_PROFILE_FUNCTION();
    size_t k = 0;
    for ( size_t i = 0; i < 1e5; ++i )
    {
        k += i;
    }
}

void testProfile()
{
    PBR_PROFILE( "customString" );
    size_t k = 0;
    for ( size_t i = 0; i < 1e5; ++i )
    {
        k += i;
    }
}

void testThreading()
{
    PBR_PROFILE_FUNCTION();

    std::vector< std::thread > threads;
    for ( int i = 0; i < 100; ++i )
    {
        threads.emplace_back( testProfile );
    }

    for ( std::thread& thread : threads )
    {
        thread.join();
    }
}

void testNestedProfile()
{
    PBR_PROFILE( "parent" );

    size_t k = 0;
    for ( size_t i = 0; i < 10; ++i )
    {
        PBR_PROFILE( "innerLoop" );
        k += i;
    }
}

TEST_CASE( "Profile" )
{
    pbr::TlProfileSetup( 1000000 );
    testProfileFunction();
    testProfile();
    testThreading();
    testNestedProfile();
    pbr::TlProfilePrint();
    pbr::TlProfileTeardown();
}