#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

/// \class Vec3f
class PBR_API Vec3f final
{
public:
    using ElementType = float;

    /// Default constructor.
    Vec3f() = default;

    /// Destructor.
    ~Vec3f() = default;

    /// Element-wise constructor.
    explicit Vec3f( const float& i_element0, const float& i_element1, const float& i_element2 )
        : m_elements{i_element0, i_element1, i_element2}
    {
        PBR_ASSERT( !HasNans() );
    }

    /// Copy constructor.
    Vec3f( const Vec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 3 );
    }

    /// Copy assignment operator.
    Vec3f& operator=( const Vec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 3 );
        return *this;
    }

    /// Element-wise index read accessor.
    float& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 3 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    const float& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 3 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    Vec3f operator+( const Vec3f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec3f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    Vec3f& operator+=( const Vec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3f operator-( const Vec3f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec3f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    Vec3f& operator-=( const Vec3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    Vec3f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    Vec3f operator/( const float& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec3f( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal, m_elements[ 2 ] * reciprocal );
    }

    Vec3f& operator/=( const float& i_scalar )
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

    /// Comparison operator
    bool operator==( const Vec3f& i_vector ) const
    {
        return m_elements[ 0 ] == i_vector.m_elements[ 0 ] && m_elements[ 1 ] == i_vector.m_elements[ 1 ] &&
               m_elements[ 2 ] == i_vector.m_elements[ 2 ];
    }

    /// Get the number of elements in this vector.
    static size_t GetElementSize()
    {
        return 3;
    }

    /// Are any of the element values NaNs?
    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] );
    }

    /// Get the string representation.  For debugging purposes.
    std::string ToString()
    {
        std::stringstream ss;
        ss << "Vec3f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << ", ";
        ss << m_elements[ 2 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 3 ] = {0, 0, 0};
};

Vec3f operator*( const Vec3f& i_vector, const float& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec3f( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar, i_vector[ 2 ] * i_scalar );
}

Vec3f operator*( const float& i_scalar, const Vec3f& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec3f( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar, i_vector[ 2 ] * i_scalar );
}

PBR_NAMESPACE_END