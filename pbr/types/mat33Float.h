#pragma once

#include <cmath>
#include <pbr/tools/assert.h>

namespace pbr
{
class Mat33Float
{
public:
    explicit Mat33Float( const float& i_element0,
                         const float& i_element1,
                         const float& i_element2,
                         const float& i_element3,
                         const float& i_element4,
                         const float& i_element5,
                         const float& i_element6,
                         const float& i_element7,
                         const float& i_element8 )
        : m_elements{i_element0,
                     i_element1,
                     i_element2,
                     i_element3,
                     i_element4,
                     i_element5,
                     i_element6,
                     i_element7,
                     i_element8}
    {
        PBR_ASSERT( !HasNans() );
    }

    float& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const float& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
    }

    Mat33Float operator+( const Mat33Float& i_matrix )
    {
        return Mat33Float( m_elements[ 0 ] + i_matrix.m_elements[ 0 ],
                           m_elements[ 1 ] + i_matrix.m_elements[ 1 ],
                           m_elements[ 2 ] + i_matrix.m_elements[ 2 ],
                           m_elements[ 3 ] + i_matrix.m_elements[ 3 ],
                           m_elements[ 4 ] + i_matrix.m_elements[ 4 ],
                           m_elements[ 5 ] + i_matrix.m_elements[ 5 ],
                           m_elements[ 6 ] + i_matrix.m_elements[ 6 ],
                           m_elements[ 7 ] + i_matrix.m_elements[ 7 ],
                           m_elements[ 8 ] + i_matrix.m_elements[ 8 ] );
    }

    Mat33Float& operator+=( const Mat33Float& i_matrix )
    {
        m_elements[ 0 ] += i_matrix.m_elements[ 0 ];
        m_elements[ 1 ] += i_matrix.m_elements[ 1 ];
        m_elements[ 2 ] += i_matrix.m_elements[ 2 ];
        m_elements[ 3 ] += i_matrix.m_elements[ 3 ];
        m_elements[ 4 ] += i_matrix.m_elements[ 4 ];
        m_elements[ 5 ] += i_matrix.m_elements[ 5 ];
        m_elements[ 6 ] += i_matrix.m_elements[ 6 ];
        m_elements[ 7 ] += i_matrix.m_elements[ 7 ];
        m_elements[ 8 ] += i_matrix.m_elements[ 8 ];
        return *this;
    }

    Mat33Float operator-( const Mat33Float& i_matrix )
    {
        return Mat33Float( m_elements[ 0 ] - i_matrix.m_elements[ 0 ],
                           m_elements[ 1 ] - i_matrix.m_elements[ 1 ],
                           m_elements[ 2 ] - i_matrix.m_elements[ 2 ],
                           m_elements[ 3 ] - i_matrix.m_elements[ 3 ],
                           m_elements[ 4 ] - i_matrix.m_elements[ 4 ],
                           m_elements[ 5 ] - i_matrix.m_elements[ 5 ],
                           m_elements[ 6 ] - i_matrix.m_elements[ 6 ],
                           m_elements[ 7 ] - i_matrix.m_elements[ 7 ],
                           m_elements[ 8 ] - i_matrix.m_elements[ 8 ] );
    }

    Mat33Float& operator-=( const Mat33Float& i_matrix )
    {
        m_elements[ 0 ] -= i_matrix.m_elements[ 0 ];
        m_elements[ 1 ] -= i_matrix.m_elements[ 1 ];
        m_elements[ 2 ] -= i_matrix.m_elements[ 2 ];
        m_elements[ 3 ] -= i_matrix.m_elements[ 3 ];
        m_elements[ 4 ] -= i_matrix.m_elements[ 4 ];
        m_elements[ 5 ] -= i_matrix.m_elements[ 5 ];
        m_elements[ 6 ] -= i_matrix.m_elements[ 6 ];
        m_elements[ 7 ] -= i_matrix.m_elements[ 7 ];
        m_elements[ 8 ] -= i_matrix.m_elements[ 8 ];
        return *this;
    }

    Mat33Float operator*( const float& i_scalar )
    {
        return Mat33Float( m_elements[ 0 ] * i_scalar,
                           m_elements[ 1 ] * i_scalar,
                           m_elements[ 2 ] * i_scalar,
                           m_elements[ 3 ] * i_scalar,
                           m_elements[ 4 ] * i_scalar,
                           m_elements[ 5 ] * i_scalar,
                           m_elements[ 6 ] * i_scalar,
                           m_elements[ 7 ] * i_scalar,
                           m_elements[ 8 ] * i_scalar );
    }

    Mat33Float& operator*=( const float& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        m_elements[ 4 ] *= i_scalar;
        m_elements[ 5 ] *= i_scalar;
        m_elements[ 6 ] *= i_scalar;
        m_elements[ 7 ] *= i_scalar;
        m_elements[ 8 ] *= i_scalar;
        return *this;
    }

    Mat33Float operator/( const float& i_scalar )
    {
        return Mat33Float( m_elements[ 0 ] / i_scalar,
                           m_elements[ 1 ] / i_scalar,
                           m_elements[ 2 ] / i_scalar,
                           m_elements[ 3 ] / i_scalar,
                           m_elements[ 4 ] / i_scalar,
                           m_elements[ 5 ] / i_scalar,
                           m_elements[ 6 ] / i_scalar,
                           m_elements[ 7 ] / i_scalar,
                           m_elements[ 8 ] / i_scalar );
    }

    Mat33Float& operator/=( const float& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        m_elements[ 3 ] /= i_scalar;
        m_elements[ 4 ] /= i_scalar;
        m_elements[ 5 ] /= i_scalar;
        m_elements[ 6 ] /= i_scalar;
        m_elements[ 7 ] /= i_scalar;
        m_elements[ 8 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] ) || std::isnan( m_elements[ 4 ] ) || std::isnan( m_elements[ 5 ] ) ||
               std::isnan( m_elements[ 6 ] ) || std::isnan( m_elements[ 7 ] ) || std::isnan( m_elements[ 8 ] );
    }

private:
    float m_elements[ 9 ] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
};
} // namespace pbr
