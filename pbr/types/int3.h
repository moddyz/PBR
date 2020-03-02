#pragma once
namespace pbr
{
class Int3
{
public:
    explicit Int3( const int& i_element0, const int& i_element1, const int& i_element2 )
        : m_elements( {i_element0, i_element1, i_element2} )
    {
    }

    Int3 operator+( const Int3& i_vector )
    {
        return Int3( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                     m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                     m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Int3& operator+=( const Int3& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Int3 operator-( const Int3& i_vector )
    {
        return Int3( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                     m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                     m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Int3& operator-=( const Int3& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Int3 operator*( const int& i_scalar )
    {
        return Int3( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Int3& operator*=( const int& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Int3 operator/( const int& i_scalar )
    {
        return Int3( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar, m_elements[ 2 ] / i_scalar );
    }

    Int3& operator/=( const int& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        return *this;
    }

private:
    int m_elements[ 3 ] = {0, 0, 0};
};
} // namespace pbr
