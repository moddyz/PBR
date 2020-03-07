#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vector2f
{
public:
    explicit Vector2f( const float& i_element0, const float& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vector2f( const Vector2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vector2f& operator=( const Vector2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
        return *this;
    }

    float& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    const float& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    Vector2f operator+( const Vector2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2f( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Vector2f& operator+=( const Vector2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Vector2f operator-( const Vector2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2f( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Vector2f& operator-=( const Vector2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vector2f operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2f( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Vector2f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vector2f operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector2f( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Vector2f& operator/=( const float& i_scalar )
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
    float m_elements[ 2 ] = {0.0f, 0.0f};
};
} // namespace pbr
