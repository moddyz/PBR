#pragma once
namespace pbr
{
class Float3
{
public:
    explicit Float3( const float& i_element0, const float& i_element1, const float& i_element2 )
        : m_elements( {i_element0, i_element1, i_element2} )
    {
    }

    Float3 operator+( const Float3& i_vector )
    {
        return Float3( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                       m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                       m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Float3& operator+=( const Float3& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Float3 operator-( const Float3& i_vector )
    {
        return Float3( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                       m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                       m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Float3& operator-=( const Float3& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Float3 operator*( const float& i_scalar )
    {
        return Float3( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Float3& operator*=( const float& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Float3 operator/( const float& i_scalar )
    {
        return Float3( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar, m_elements[ 2 ] / i_scalar );
    }

    Float3& operator/=( const float& i_scalar )
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
