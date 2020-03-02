#pragma once
namespace pbr
{
class Int4
{
public:
    explicit Int4( const int& i_element0, const int& i_element1, const int& i_element2, const int& i_element3 )
        : m_elements( {i_element0, i_element1, i_element2, i_element3} )
    {
    }

    Int4 operator+( const Int4& i_vector )
    {
        return Int4( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                     m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                     m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                     m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    Int4& operator+=( const Int4& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    Int4 operator-( const Int4& i_vector )
    {
        return Int4( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                     m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                     m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                     m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    Int4& operator-=( const Int4& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    Int4 operator*( const int& i_scalar )
    {
        return Int4( m_elements[ 0 ] * i_scalar,
                     m_elements[ 1 ] * i_scalar,
                     m_elements[ 2 ] * i_scalar,
                     m_elements[ 3 ] * i_scalar );
    }

    Int4& operator*=( const int& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    Int4 operator/( const int& i_scalar )
    {
        return Int4( m_elements[ 0 ] / i_scalar,
                     m_elements[ 1 ] / i_scalar,
                     m_elements[ 2 ] / i_scalar,
                     m_elements[ 3 ] / i_scalar );
    }

    Int4& operator/=( const int& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        m_elements[ 3 ] /= i_scalar;
        return *this;
    }

private:
    int m_elements[ 4 ] = {0, 0, 0, 0};
};
} // namespace pbr
