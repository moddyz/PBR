#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vec2Float final
{
public:
    Vec2Float()  = default;
    ~Vec2Float() = default;

    explicit Vec2Float( const float& i_element0, const float& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vec2Float( const Vec2Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vec2Float& operator=( const Vec2Float& i_vector )
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

    Vec2Float operator+( const Vec2Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Float( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Vec2Float& operator+=( const Vec2Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Float operator-( const Vec2Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Float( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Vec2Float& operator-=( const Vec2Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Float operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vec2Float( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Vec2Float& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vec2Float operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec2Float( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal );
    }

    Vec2Float& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
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
