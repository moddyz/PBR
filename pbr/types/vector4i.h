#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vector4i
{
public:
    explicit Vector4i( const int& i_element0, const int& i_element1, const int& i_element2, const int& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        PBR_ASSERT( !HasNans() );
    }

    Vector4i( const Vector4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    Vector4i& operator=( const Vector4i& i_vector )
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

    Vector4i operator+( const Vector4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector4i( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                         m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                         m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                         m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    Vector4i& operator+=( const Vector4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    Vector4i operator-( const Vector4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector4i( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                         m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                         m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                         m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    Vector4i& operator-=( const Vector4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    Vector4i operator*( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector4i( m_elements[ 0 ] * i_scalar,
                         m_elements[ 1 ] * i_scalar,
                         m_elements[ 2 ] * i_scalar,
                         m_elements[ 3 ] * i_scalar );
    }

    Vector4i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    Vector4i operator/( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector4i( m_elements[ 0 ] / i_scalar,
                         m_elements[ 1 ] / i_scalar,
                         m_elements[ 2 ] / i_scalar,
                         m_elements[ 3 ] / i_scalar );
    }

    Vector4i& operator/=( const int& i_scalar )
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
    int m_elements[ 4 ] = {0, 0, 0, 0};
};
} // namespace pbr
