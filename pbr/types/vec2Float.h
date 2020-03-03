#pragma once
#include <cmath>
namespace pbr
{
class Vec2Float
{
public:
    explicit Vec2Float( const float& i_element0, const float& i_element1 )
        : m_elements{i_element0, i_element1}
    {
    }

    float& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const float& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
    }

    Vec2Float operator+( const Vec2Float& i_vector )
    {
        return Vec2Float( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    Vec2Float& operator+=( const Vec2Float& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Float operator-( const Vec2Float& i_vector )
    {
        return Vec2Float( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    Vec2Float& operator-=( const Vec2Float& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2Float operator*( const float& i_scalar )
    {
        return Vec2Float( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    Vec2Float& operator*=( const float& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vec2Float operator/( const float& i_scalar )
    {
        return Vec2Float( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar );
    }

    Vec2Float& operator/=( const float& i_scalar )
    {
        m_elements[ 0 ] /= i_scalar;
        m_elements[ 1 ] /= i_scalar;
        return *this;
    }

    bool HasNans() const
    {
        std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

private:
    float m_elements[ 2 ] = {0.0f, 0.0f};
};
} // namespace pbr
