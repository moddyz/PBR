#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vec3Float final
{
public:
    using ElementType = float;

    Vec3Float()  = default;
    ~Vec3Float() = default;

    explicit Vec3Float( const float& i_element0, const float& i_element1, const float& i_element2 )
        : m_elements{i_element0, i_element1, i_element2}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vec3Float( const Vec3Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vec3Float& operator=( const Vec3Float& i_vector )
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

    Vec3Float operator+( const Vec3Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec3Float( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                          m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                          m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Vec3Float& operator+=( const Vec3Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3Float operator-( const Vec3Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec3Float( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                          m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                          m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Vec3Float& operator-=( const Vec3Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3Float operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vec3Float( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Vec3Float& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Vec3Float operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec3Float( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal, m_elements[ 2 ] * reciprocal );
    }

    Vec3Float& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        return *this;
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] );
    }

private:
    float m_elements[ 3 ] = {0.0f, 0.0f, 0.0f};
};
} // namespace pbr
