#pragma once

#include <pbr/api.h>

#include <pbr/type/bounds3f.h>
#include <pbr/type/bounds3i.h>

#include <pbr/function/boundsDiagonal.h>

PBR_NAMESPACE_BEGIN

/// Computes the index of the bounding box axes which is the longest.

PBR_API
inline void FnBoundsMaxExtent( const Bounds3i& i_bounds, size_t& o_maxExtentIndex )
{
    Vec3i diagonal;
    FnBoundsDiagonal( i_bounds, diagonal );
    if ( diagonal[ 0 ] > diagonal[ 1 ] && diagonal[ 0 ] > diagonal[ 2 ] )
    {
        o_maxExtentIndex = 0;
    }
    else
    {
        if ( diagonal[ 1 ] > diagonal[ 2 ] )
        {
            o_maxExtentIndex = 1;
        }
        else
        {
            o_maxExtentIndex = 2;
        }
    }
}

PBR_API
inline void FnBoundsMaxExtent( const Bounds3f& i_bounds, size_t& o_maxExtentIndex )
{
    Vec3f diagonal;
    FnBoundsDiagonal( i_bounds, diagonal );
    if ( diagonal[ 0 ] > diagonal[ 1 ] && diagonal[ 0 ] > diagonal[ 2 ] )
    {
        o_maxExtentIndex = 0;
    }
    else
    {
        if ( diagonal[ 1 ] > diagonal[ 2 ] )
        {
            o_maxExtentIndex = 1;
        }
        else
        {
            o_maxExtentIndex = 2;
        }
    }
}

PBR_NAMESPACE_END