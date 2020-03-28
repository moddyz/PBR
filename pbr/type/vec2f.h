#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tool/almost.h>
#include <pbr/tool/assert.h>

PBR_NAMESPACE_BEGIN

/// \class Vec2f
class PBR_API Vec2f final
{
public:
    using ElementType = float;

    /// Default constructor.
    Vec2f() = default;

    /// Destructor.
    ~Vec2f() = default;

    /// Element-wise constructor.
    explicit Vec2f( const float& i_element0, const float& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

#ifdef PBR_DEBUG
    /// Copy constructor.
    Vec2f( const Vec2f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 2 );
        PBR_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Vec2f& operator=( const Vec2f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 2 );
        PBR_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    inline float& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 2 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    inline const float& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 2 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    inline Vec2f operator+( const Vec2f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec2f( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    /// Addition assignment.
    inline Vec2f& operator+=( const Vec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    /// Subtraction.
    inline Vec2f operator-( const Vec2f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec2f( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    /// Unary negation.
    inline Vec2f operator-() const
    {
        PBR_ASSERT( !HasNans() );
        return Vec2f( -m_elements[ 0 ], -m_elements[ 1 ] );
    }

    inline Vec2f& operator-=( const Vec2f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    inline Vec2f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    inline Vec2f operator/( const float& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec2f( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal );
    }

    inline Vec2f& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        return *this;
    }
    inline float X() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
    inline float Y() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }

    /// Comparison operator
    inline bool operator==( const Vec2f& i_vector ) const
    {
        return AlmostEqual( m_elements[ 0 ], i_vector.m_elements[ 0 ] ) &&
               AlmostEqual( m_elements[ 1 ], i_vector.m_elements[ 1 ] );
    }

    /// Not equal operator
    inline bool operator!=( const Vec2f& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    /// Get the number of elements in this vector.
    inline static size_t GetElementSize()
    {
        return 2;
    }

    /// Are any of the element values NaNs?
    inline bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string ToString() const
    {
        std::stringstream ss;
        ss << "Vec2f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 2 ] = {0, 0};
};

inline Vec2f operator*( const Vec2f& i_vector, const float& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec2f( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar );
}

inline Vec2f operator*( const float& i_scalar, const Vec2f& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec2f( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar );
}

PBR_NAMESPACE_END