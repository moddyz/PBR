#pragma once

#include <cmath>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vector3i
{
public:
    explicit Vector3i( const int& i_element0, const int& i_element1, const int& i_element2 )
        : m_elements{i_element0, i_element1, i_element2}
    {
        PBR_ASSERT( !HasNans() );
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

    Vector3i operator+( const Vector3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector3i( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                         m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                         m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Vector3i& operator+=( const Vector3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Vector3i operator-( const Vector3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return Vector3i( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                         m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                         m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Vector3i& operator-=( const Vector3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Vector3i operator*( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector3i( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Vector3i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Vector3i operator/( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return Vector3i( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar, m_elements[ 2 ] / i_scalar );
    }

    Vector3i& operator/=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        PBR_ASSERT( !HasNans() );
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] );
    }

private:
    int m_elements[ 3 ] = {0, 0, 0};
};
} // namespace pbr
