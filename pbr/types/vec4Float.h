#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vec4Float final
{
public:
    Vec4Float()  = default;
    ~Vec4Float() = default;

    explicit Vec4Float( const float& i_element0,
                        const float& i_element1,
                        const float& i_element2,
                        const float& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vec4Float( const Vec4Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vec4Float& operator=( const Vec4Float& i_vector )
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

    Vec4Float operator+( const Vec4Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec4Float( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                          m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                          m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                          m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    Vec4Float& operator+=( const Vec4Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    Vec4Float operator-( const Vec4Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vec4Float( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                          m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                          m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                          m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    Vec4Float& operator-=( const Vec4Float& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    Vec4Float operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vec4Float( m_elements[ 0 ] * i_scalar,
                          m_elements[ 1 ] * i_scalar,
                          m_elements[ 2 ] * i_scalar,
                          m_elements[ 3 ] * i_scalar );
    }

    Vec4Float& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    Vec4Float operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vec4Float( m_elements[ 0 ] / i_scalar,
                          m_elements[ 1 ] / i_scalar,
                          m_elements[ 2 ] / i_scalar,
                          m_elements[ 3 ] / i_scalar );
    }

    Vec4Float& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        m_elements[ 3 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        PBR_ASSERT( !HasNans() );
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] );
    }

private:
    float m_elements[ 4 ] = {0.0f, 0.0f, 0.0f, 0.0f};
};
} // namespace pbr
