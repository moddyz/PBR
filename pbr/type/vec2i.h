#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tool/assert.h>

PBR_NAMESPACE_BEGIN

/// \class Vec2i
class PBR_API Vec2i final
{
public:
    using ElementType = int;

    /// Default constructor.
    Vec2i() = default;

    /// Destructor.
    ~Vec2i() = default;

    /// Element-wise constructor.
    explicit Vec2i( const int& i_element0, const int& i_element1 )
        : m_elements{i_element0, i_element1}
    {
        PBR_ASSERT( !HasNans() );
    }

#ifdef PBR_DEBUG
    /// Copy constructor.
    Vec2i( const Vec2i& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( int ) * 2 );
        PBR_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Vec2i& operator=( const Vec2i& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( int ) * 2 );
        PBR_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    int& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 2 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    const int& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 2 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    Vec2i operator+( const Vec2i& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec2i( m_elements[ 0 ] + i_vector.m_elements[ 0 ], m_elements[ 1 ] + i_vector.m_elements[ 1 ] );
    }

    /// Addition assignment.
    Vec2i& operator+=( const Vec2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        return *this;
    }

    /// Subtraction.
    Vec2i operator-( const Vec2i& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec2i( m_elements[ 0 ] - i_vector.m_elements[ 0 ], m_elements[ 1 ] - i_vector.m_elements[ 1 ] );
    }

    /// Unary negation.
    Vec2i operator-() const
    {
        PBR_ASSERT( !HasNans() );
        return Vec2i( -m_elements[ 0 ], -m_elements[ 1 ] );
    }

    Vec2i& operator-=( const Vec2i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        return *this;
    }

    Vec2i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        return *this;
    }

    Vec2i operator/( const int& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        return Vec2i( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal );
    }

    Vec2i& operator/=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
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

    /// Comparison operator
    bool operator==( const Vec2i& i_vector ) const
    {
        return m_elements[ 0 ] == i_vector.m_elements[ 0 ] && m_elements[ 1 ] == i_vector.m_elements[ 1 ];
    }

    /// Get the number of elements in this vector.
    static size_t GetElementSize()
    {
        return 2;
    }

    /// Are any of the element values NaNs?
    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] );
    }

    /// Get the string representation.  For debugging purposes.
    std::string ToString()
    {
        std::stringstream ss;
        ss << "Vec2i( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << " )";
        return ss.str();
    }

private:
    int m_elements[ 2 ] = {0, 0};
};

Vec2i operator*( const Vec2i& i_vector, const int& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec2i( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar );
}

Vec2i operator*( const int& i_scalar, const Vec2i& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec2i( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar );
}

PBR_NAMESPACE_END