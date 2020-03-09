#pragma once

#include <cmath>
#include <cstring>
#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

class PBR_API DtVec4i final
{
public:
    using ElementType = int;

    static size_t GetElementSize()
    {
        return 4;
    }

    DtVec4i()  = default;
    ~DtVec4i() = default;

    explicit DtVec4i( const int& i_element0, const int& i_element1, const int& i_element2, const int& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        PBR_ASSERT( !HasNans() );
    }

    DtVec4i( const DtVec4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    DtVec4i& operator=( const DtVec4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
        return *this;
    }

    int& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    const int& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ i_index ];
    }

    DtVec4i operator+( const DtVec4i& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return DtVec4i( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    DtVec4i& operator+=( const DtVec4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    DtVec4i operator-( const DtVec4i& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return DtVec4i( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    DtVec4i& operator-=( const DtVec4i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    DtVec4i operator*( const int& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        return DtVec4i( m_elements[ 0 ] * i_scalar,
                        m_elements[ 1 ] * i_scalar,
                        m_elements[ 2 ] * i_scalar,
                        m_elements[ 3 ] * i_scalar );
    }

    DtVec4i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    DtVec4i operator/( const int& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        return DtVec4i( m_elements[ 0 ] * reciprocal,
                        m_elements[ 1 ] * reciprocal,
                        m_elements[ 2 ] * reciprocal,
                        m_elements[ 3 ] * reciprocal );
    }

    DtVec4i& operator/=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        m_elements[ 3 ] *= reciprocal;
        return *this;
    }

    int X() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }

    int Y() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }

    int Z() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }

    int W() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] );
    }

private:
    int m_elements[ 4 ] = {0, 0, 0, 0};
};
PBR_NAMESPACE_END
