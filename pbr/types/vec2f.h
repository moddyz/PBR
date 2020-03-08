#pragma once

#include <cmath>
#include <cstring>
#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

class PBR_API DtVec2f final
{
public:
    using ElementType = float;

    DtVec2f()  = default;
    ~DtVec2f() = default;

    explicit DtVec2f( const float& i_element0, const float& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

    DtVec2f( const DtVec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    DtVec2f& operator=( const DtVec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
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

    DtVec2f operator+( const DtVec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec2f( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    DtVec2f& operator+=( const DtVec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    DtVec2f operator-( const DtVec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec2f( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    DtVec2f& operator-=( const DtVec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    DtVec2f operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec2f( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar );
    }

    DtVec2f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    DtVec2f operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return DtVec2f( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal );
    }

    DtVec2f& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        return *this;
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

private:
    float m_elements[ 2 ] = {0.0f, 0.0f};
};
PBR_NAMESPACE_END
