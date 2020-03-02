#pragma once
namespace pbr
{
class Float4
{
public:
    explicit Float4( const float& i_element0,
                     const float& i_element1,
                     const float& i_element2,
                     const float& i_element3 )
        : m_elements( {i_element0, i_element1, i_element2, i_element3} )
    {
    }

    Float4 operator+( const Float4& i_vector )
    {
        return Float4( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                       m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                       m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                       m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    Float4& operator+=( const Float4& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    Float4 operator-( const Float4& i_vector )
    {
        return Float4( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                       m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                       m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                       m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    Float4& operator-=( const Float4& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    Float4 operator*( const float& i_scalar )
    {
        return Float4( m_elements[ 0 ] * i_scalar,
                       m_elements[ 1 ] * i_scalar,
                       m_elements[ 2 ] * i_scalar,
                       m_elements[ 3 ] * i_scalar );
    }

    Float4& operator*=( const float& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    Float4 operator/( const float& i_scalar )
    {
        return Float4( m_elements[ 0 ] / i_scalar,
                       m_elements[ 1 ] / i_scalar,
                       m_elements[ 2 ] / i_scalar,
                       m_elements[ 3 ] / i_scalar );
    }

    Float4& operator/=( const float& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        m_elements[ 2 ] /= i_scalar;
        m_elements[ 3 ] /= i_scalar;
        return *this;
    }

private:
    float m_elements[ 4 ] = {0.0f, 0.0f, 0.0f, 0.0f};
};
} // namespace pbr
