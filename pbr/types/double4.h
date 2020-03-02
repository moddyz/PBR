#pragma once
namespace pbr
{
class Double4
{
public:
    explicit Double4( const double& i_element0,
                      const double& i_element1,
                      const double& i_element2,
                      const double& i_element3 )
        : m_elements( {i_element0, i_element1, i_element2, i_element3} )
    {
    }

    Double4 operator+( const Double4& i_vector )
    {
        return Double4( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    Double4& operator+=( const Double4& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    Double4 operator-( const Double4& i_vector )
    {
        return Double4( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    Double4& operator-=( const Double4& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    Double4 operator*( const double& i_scalar )
    {
        return Double4( m_elements[ 0 ] * i_scalar,
                        m_elements[ 1 ] * i_scalar,
                        m_elements[ 2 ] * i_scalar,
                        m_elements[ 3 ] * i_scalar );
    }

    Double4& operator*=( const double& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    Double4 operator/( const double& i_scalar )
    {
        return Double4( m_elements[ 0 ] / i_scalar,
                        m_elements[ 1 ] / i_scalar,
                        m_elements[ 2 ] / i_scalar,
                        m_elements[ 3 ] / i_scalar );
    }

    Double4& operator/=( const double& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        m_elements[ 3 ] /= i_scalar;
        return *this;
    }

private:
    double m_elements[ 4 ] = {0.0, 0.0, 0.0, 0.0};
};
} // namespace pbr
