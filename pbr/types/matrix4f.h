#pragma once

#include <cmath>
#include <pbr/tools/assert.h>

namespace pbr
{
class Matrix4f
{
public:
    explicit Matrix4f( const float& i_element0,
                       const float& i_element1,
                       const float& i_element2,
                       const float& i_element3,
                       const float& i_element4,
                       const float& i_element5,
                       const float& i_element6,
                       const float& i_element7,
                       const float& i_element8,
                       const float& i_element9,
                       const float& i_element10,
                       const float& i_element11,
                       const float& i_element12,
                       const float& i_element13,
                       const float& i_element14,
                       const float& i_element15 )
        : m_elements{i_element0,
                     i_element1,
                     i_element2,
                     i_element3,
                     i_element4,
                     i_element5,
                     i_element6,
                     i_element7,
                     i_element8,
                     i_element9,
                     i_element10,
                     i_element11,
                     i_element12,
                     i_element13,
                     i_element14,
                     i_element15}
    {
        PBR_ASSERT( !HasNans() );
    }

    float& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const float& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
    }

    float& operator()( size_t i_row, size_t i_column )
    {
        return m_elements[ ( i_row * 4 ) + i_column ];
    }

    const float& operator()( size_t i_row, size_t i_column ) const
    {
        return m_elements[ ( i_row * 4 ) + i_column ];
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] ) || std::isnan( m_elements[ 4 ] ) || std::isnan( m_elements[ 5 ] ) ||
               std::isnan( m_elements[ 6 ] ) || std::isnan( m_elements[ 7 ] ) || std::isnan( m_elements[ 8 ] ) ||
               std::isnan( m_elements[ 9 ] ) || std::isnan( m_elements[ 10 ] ) || std::isnan( m_elements[ 11 ] ) ||
               std::isnan( m_elements[ 12 ] ) || std::isnan( m_elements[ 13 ] ) || std::isnan( m_elements[ 14 ] ) ||
               std::isnan( m_elements[ 15 ] );
    }

private:
    float m_elements[ 16 ] =
        {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
};
} // namespace pbr
