#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vec2Int
{
public:
    explicit Vec2Int( const int& i_element0, const int& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vec2Int( const Vec2Int& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vec2Int& operator=( const Vec2Int& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
        return *this;
    }

    int& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    const int& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    Vec2Int operator+( const Vec2Int& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Int( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Vec2Int& operator+=( const Vec2Int& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Int operator-( const Vec2Int& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Int( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Vec2Int& operator-=( const Vec2Int& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Int operator*( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Int( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Vec2Int& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vec2Int operator/( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Int( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Vec2Int& operator/=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        PBR_ASSERT( !HasNans() );
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

private:
    int m_elements[ 2 ] = {0, 0};
};
} // namespace pbr
