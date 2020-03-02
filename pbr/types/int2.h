#pragma once
namespace pbr
{
class Int2
{
public:
    explicit Int2( const int& i_element0, const int& i_element1 )
        : m_elements( {i_element0, i_element1} )
    {
    }

    Int2 operator+( const Int2& i_vector )
    {
        return Int2( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Int2& operator+=( const Int2& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Int2 operator-( const Int2& i_vector )
    {
        return Int2( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Int2& operator-=( const Int2& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Int2 operator*( const int& i_scalar )
    {
        return Int2( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Int2& operator*=( const int& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Int2 operator/( const int& i_scalar )
    {
        return Int2( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Int2& operator/=( const int& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        return *this;
    }

private:
    int m_elements[ 2 ] = {0, 0};
};
} // namespace pbr
