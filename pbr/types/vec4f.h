#pragma once

#include <cmath>
#include <cstring>
#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

class PBR_API DtVec4f final
{
public:
    using ElementType = float;

    DtVec4f()  = default;
    ~DtVec4f() = default;

    explicit DtVec4f( const float& i_element0,
                      const float& i_element1,
                      const float& i_element2,
                      const float& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        PBR_ASSERT( !HasNans() );
    }

    DtVec4f( const DtVec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( m_elements ) );
    }

    DtVec4f& operator=( const DtVec4f& i_vector )
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

    DtVec4f operator+( const DtVec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec4f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    DtVec4f& operator+=( const DtVec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    DtVec4f operator-( const DtVec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec4f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                        m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                        m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                        m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    DtVec4f& operator-=( const DtVec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    DtVec4f operator*( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        return DtVec4f( m_elements[ 0 ] * i_scalar,
                        m_elements[ 1 ] * i_scalar,
                        m_elements[ 2 ] * i_scalar,
                        m_elements[ 3 ] * i_scalar );
    }

    DtVec4f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    DtVec4f operator/( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return DtVec4f( m_elements[ 0 ] * reciprocal,
                        m_elements[ 1 ] * reciprocal,
                        m_elements[ 2 ] * reciprocal,
                        m_elements[ 3 ] * reciprocal );
    }

    DtVec4f& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        m_elements[ 3 ] *= reciprocal;
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

    float W() const
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
    float m_elements[ 4 ] = {0.0f, 0.0f, 0.0f, 0.0f};
};
PBR_NAMESPACE_END
