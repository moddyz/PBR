#pragma once
namespace pbr
{
class Double2
{
public:
    explicit Double2( const double& i_element0, const double& i_element1 )
        : m_elements( {i_element0, i_element1} )
    {
    }

    Double2 operator+( const Double2& i_vector )
    {
        return Double2( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Double2& operator+=( const Double2& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Double2 operator-( const Double2& i_vector )
    {
        return Double2( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Double2& operator-=( const Double2& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Double2 operator*( const double& i_scalar )
    {
        return Double2( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Double2& operator*=( const double& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Double2 operator/( const double& i_scalar )
    {
        return Double2( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Double2& operator/=( const double& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        return *this;
    }

private:
    double m_elements[ 2 ] = {0.0, 0.0};
};
} // namespace pbr
