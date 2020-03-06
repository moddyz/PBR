#pragma once

#include <cmath>
#include <pbr/tools/assert.h>

namespace pbr
{
class Mat44Int
{
public:
    explicit Mat44Int( const int& i_element0,
                       const int& i_element1,
                       const int& i_element2,
                       const int& i_element3,
                       const int& i_element4,
                       const int& i_element5,
                       const int& i_element6,
                       const int& i_element7,
                       const int& i_element8,
                       const int& i_element9,
                       const int& i_element10,
                       const int& i_element11,
                       const int& i_element12,
                       const int& i_element13,
                       const int& i_element14,
                       const int& i_element15 )
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

    int& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const int& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
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
    int m_elements[ 16 ] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};
} // namespace pbr
