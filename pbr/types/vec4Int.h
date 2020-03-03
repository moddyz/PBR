#pragma once

#include <cmath>
#include <pbr/tools/assert.h>

namespace pbr
{
class Vec4Int
{
public:
    explicit Vec4Int( const int& i_element0, const int& i_element1, const int& i_element2, const int& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
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

    Vec4Int operator+( const Vec4Int& i_vector )
    {
        return Vec4Int( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    Vec4Int& operator+=( const Vec4Int& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    Vec4Int operator-( const Vec4Int& i_vector )
    {
        return Vec4Int( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    Vec4Int& operator-=( const Vec4Int& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    Vec4Int operator*( const int& i_scalar )
    {
        return Vec4Int( m_elements[ 0 ] * i_scalar,
                        m_elements[ 1 ] * i_scalar,
                        m_elements[ 2 ] * i_scalar,
                        m_elements[ 3 ] * i_scalar );
    }

    Vec4Int& operator*=( const int& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    Vec4Int operator/( const int& i_scalar )
    {
        return Vec4Int( m_elements[ 0 ] / i_scalar,
                        m_elements[ 1 ] / i_scalar,
                        m_elements[ 2 ] / i_scalar,
                        m_elements[ 3 ] / i_scalar );
    }

    Vec4Int& operator/=( const int& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        m_elements[ 3 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
            std::isnan( m_elements[ 3 ] );
    }

private:
    int m_elements[ 4 ] = {0, 0, 0, 0};
};
} // namespace pbr
