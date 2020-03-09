#pragma once

#include <cmath>
#include <cstring>
#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

class PBR_API DtVec3i final
{
public:
    using ElementType = int;

    DtVec3i()  = default;
    ~DtVec3i() = default;

    explicit DtVec3i( const int& i_element0, const int& i_element1, const int& i_element2 )
        : m_elements{i_element0, i_element1, i_element2}
    {
        PBR_ASSERT( !HasNans() );
    }

    DtVec3i( const DtVec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    DtVec3i& operator=( const DtVec3i& i_vector )
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

    DtVec3i operator+( const DtVec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec3i( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    DtVec3i& operator+=( const DtVec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    DtVec3i operator-( const DtVec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec3i( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    DtVec3i& operator-=( const DtVec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    DtVec3i operator*( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec3i( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    DtVec3i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    DtVec3i operator/( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        return DtVec3i( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal, m_elements[ 2 ] * reciprocal );
    }

    DtVec3i& operator/=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
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

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] );
    }

private:
    int m_elements[ 3 ] = {0, 0, 0};
};
PBR_NAMESPACE_END
