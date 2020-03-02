#pragma once
namespace pbr
{
class Float2
{
public:
    explicit Float2( const float& i_element0, const float& i_element1 )
        : m_elements( {i_element0, i_element1} )
    {
    }

    Float2 operator+( const Float2& i_vector )
    {
        return Float2( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Float2& operator+=( const Float2& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Float2 operator-( const Float2& i_vector )
    {
        return Float2( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Float2& operator-=( const Float2& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Float2 operator*( const float& i_scalar )
    {
        return Float2( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Float2& operator*=( const float& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Float2 operator/( const float& i_scalar )
    {
        return Float2( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Float2& operator/=( const float& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        return *this;
    }

private:
    float m_elements[ 2 ] = {0.0f, 0.0f};
};
} // namespace pbr
