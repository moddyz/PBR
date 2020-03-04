#pragma once

#include <cmath>
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

    int& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const int& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
    }

    Vec2Int operator+( const Vec2Int& i_vector )
    {
        return Vec2Int( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Vec2Int& operator+=( const Vec2Int& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Int operator-( const Vec2Int& i_vector )
    {
        return Vec2Int( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Vec2Int& operator-=( const Vec2Int& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Int operator*( const int& i_scalar )
    {
        return Vec2Int( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Vec2Int& operator*=( const int& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vec2Int operator/( const int& i_scalar )
    {
        return Vec2Int( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Vec2Int& operator/=( const int& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

private:
    int m_elements[ 2 ] = {0, 0};
};
} // namespace pbr
