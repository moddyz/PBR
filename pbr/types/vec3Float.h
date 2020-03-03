#pragma once
namespace pbr
{
class Vec3Float
{
public:
    explicit Vec3Float( const float& i_element0, const float& i_element1, const float& i_element2 )
        : m_elements( {i_element0, i_element1, i_element2} )
    {
    }

    Vec3Float operator+( const Vec3Float& i_vector )
    {
        return Vec3Float( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                          m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                          m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Vec3Float& operator+=( const Vec3Float& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3Float operator-( const Vec3Float& i_vector )
    {
        return Vec3Float( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                          m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                          m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Vec3Float& operator-=( const Vec3Float& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3Float operator*( const float& i_scalar )
    {
        return Vec3Float( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Vec3Float& operator*=( const float& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Vec3Float operator/( const float& i_scalar )
    {
        return Vec3Float( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar, m_elements[ 2 ] / i_scalar );
    }

    Vec3Float& operator/=( const float& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        return *this;
    }

private:
    float m_elements[ 3 ] = {0.0f, 0.0f, 0.0f};
};
} // namespace pbr
