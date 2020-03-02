#pragma once
namespace pbr
{
class Double3
{
public:
    explicit Double3( const double& i_element0, const double& i_element1, const double& i_element2 )
        : m_elements( {i_element0, i_element1, i_element2} )
    {
    }

    Double3 operator+( const Double3& i_vector )
    {
        return Double3( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Double3& operator+=( const Double3& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Double3 operator-( const Double3& i_vector )
    {
        return Double3( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Double3& operator-=( const Double3& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Double3 operator*( const double& i_scalar )
    {
        return Double3( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Double3& operator*=( const double& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Double3 operator/( const double& i_scalar )
    {
        return Double3( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar, m_elements[ 2 ] / i_scalar );
    }

    Double3& operator/=( const double& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        return *this;
    }

private:
    double m_elements[ 3 ] = {0.0, 0.0, 0.0};
};
} // namespace pbr
