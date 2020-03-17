#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

#include <pbr/type/bounds2i.h>
#include <pbr/type/vec2iArray.h>
#include <pbr/type/vec2iRange.h>

TEST_CASE( "testVec2iRange" )
{
    pbr::Bounds2i bounds( pbr::Vec2i( 0, 0 ), pbr::Vec2i( 5, 5 ) );

    pbr::Vec2iArray array;
    for ( const pbr::Vec2i& point : pbr::Vec2iRange( bounds.Min(), bounds.Max() ) )
    {
        array.push_back( point );
    }

    pbr::Vec2iArray expectedArray = {
        pbr::Vec2i( 0, 0 ), pbr::Vec2i( 1, 0 ), pbr::Vec2i( 2, 0 ), pbr::Vec2i( 3, 0 ), pbr::Vec2i( 4, 0 ),
        pbr::Vec2i( 0, 1 ), pbr::Vec2i( 1, 1 ), pbr::Vec2i( 2, 1 ), pbr::Vec2i( 3, 1 ), pbr::Vec2i( 4, 1 ),
        pbr::Vec2i( 0, 2 ), pbr::Vec2i( 1, 2 ), pbr::Vec2i( 2, 2 ), pbr::Vec2i( 3, 2 ), pbr::Vec2i( 4, 2 ),
        pbr::Vec2i( 0, 3 ), pbr::Vec2i( 1, 3 ), pbr::Vec2i( 2, 3 ), pbr::Vec2i( 3, 3 ), pbr::Vec2i( 4, 3 ),
        pbr::Vec2i( 0, 4 ), pbr::Vec2i( 1, 4 ), pbr::Vec2i( 2, 4 ), pbr::Vec2i( 3, 4 ), pbr::Vec2i( 4, 4 )};

    CHECK( array == expectedArray );
}
