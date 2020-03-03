#pragma once
namespace pbr
{
class Vec3Int
{
public:
    explicit Vec3Int( const int& i_element0, const int& i_element1, const int& i_element2 )
        : m_elements( {i_element0, i_element1, i_element2} )
    {
    }

    Vec3Int& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const Vec3Int& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
    }

    Vec3Int operator+( const Vec3Int& i_vector )
    {
        return Vec3Int( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Vec3Int& operator+=( const Vec3Int& i_vector )
    {
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3Int operator-( const Vec3Int& i_vector )
    {
        return Vec3Int( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Vec3Int& operator-=( const Vec3Int& i_vector )
    {
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3Int operator*( const int& i_scalar )
    {
        return Vec3Int( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    Vec3Int& operator*=( const int& i_scalar )
    {
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Vec3Int operator/( const int& i_scalar )
    {
        return Vec3Int( m_elements[ 0 ] / i_scalar, m_elements[ 1 ] / i_scalar, m_elements[ 2 ] / i_scalar );
    }

    Vec3Int& operator/=( const int& i_scalar )
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
