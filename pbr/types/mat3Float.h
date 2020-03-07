#pragma once

#include <cmath>
#include <cstring>
#include <pbr/tools/assert.h>

namespace pbr
{
class Mat3Float
{
public:
    explicit Mat3Float( const float& i_element0,
                        const float& i_element1,
                        const float& i_element2,
                        const float& i_element3,
                        const float& i_element4,
                        const float& i_element5,
                        const float& i_element6,
                        const float& i_element7,
                        const float& i_element8 )
        : m_elements{i_element0,
                     i_element1,
                     i_element2,
                     i_element3,
                     i_element4,
                     i_element5,
                     i_element6,
                     i_element7,
                     i_element8}
    {
        PBR_ASSERT( !HasNans() );
    }

    Mat3Float( const Mat3Float& i_matrix )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_matrix.m_elements, sizeof( m_elements ) );
    }

    Mat3Float& operator=( const Mat3Float& i_matrix )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_matrix.m_elements, sizeof( m_elements ) );
        return *this;
    }

    float& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    const float& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    float& operator()( size_t i_row, size_t i_column )
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ ( i_row * 3 ) + i_column ];
    }

    const float& operator()( size_t i_row, size_t i_column ) const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ ( i_row * 3 ) + i_column ];
    }

    bool HasNans() const
    {
        PBR_ASSERT( !HasNans() );
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] ) || std::isnan( m_elements[ 4 ] ) || std::isnan( m_elements[ 5 ] ) ||
               std::isnan( m_elements[ 6 ] ) || std::isnan( m_elements[ 7 ] ) || std::isnan( m_elements[ 8 ] );
    }

private:
    float m_elements[ 9 ] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
};
} // namespace pbr
