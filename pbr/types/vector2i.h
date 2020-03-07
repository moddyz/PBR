#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vector2i
{
public:
    explicit Vector2i( const int& i_element0, const int& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vector2i( const Vector2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vector2i& operator=( const Vector2i& i_vector )
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

    Vector2i operator+( const Vector2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2i( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Vector2i& operator+=( const Vector2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Vector2i operator-( const Vector2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2i( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Vector2i& operator-=( const Vector2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vector2i operator*( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2i( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Vector2i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vector2i operator/( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2i( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Vector2i& operator/=( const int& i_scalar )
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
