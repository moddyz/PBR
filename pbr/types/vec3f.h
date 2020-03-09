#pragma once

#include <cmath>
#include <cstring>
#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

class PBR_API DtVec3f final
{
public:
    using ElementType = float;

    DtVec3f()  = default;
    ~DtVec3f() = default;

    explicit DtVec3f( const float& i_element0, const float& i_element1, const float& i_element2 )
        : m_elements{i_element0, i_element1, i_element2}
    {
        PBR_ASSERT( !HasNans() );
    }

    DtVec3f( const DtVec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    DtVec3f& operator=( const DtVec3f& i_vector )
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

    DtVec3f operator+( const DtVec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec3f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    DtVec3f& operator+=( const DtVec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    DtVec3f operator-( const DtVec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec3f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    DtVec3f& operator-=( const DtVec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    DtVec3f operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec3f( m_elements[ 0 ] * i_scalar, m_elements[ 1 ] * i_scalar, m_elements[ 2 ] * i_scalar );
    }

    DtVec3f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    DtVec3f operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return DtVec3f( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal, m_elements[ 2 ] * reciprocal );
    }

    DtVec3f& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        return *this;
    }

    float X() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }

    float Y() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }

    float Z() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] );
    }

private:
    float m_elements[ 3 ] = {0.0f, 0.0f, 0.0f};
};
PBR_NAMESPACE_END
