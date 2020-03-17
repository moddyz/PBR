#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tool/assert.h>

PBR_NAMESPACE_BEGIN

/// \class Vec3i
class PBR_API Vec3i final
{
public:
    using ElementType = int;

    /// Default constructor.
    Vec3i() = default;

    /// Destructor.
    ~Vec3i() = default;

    /// Element-wise constructor.
    explicit Vec3i( const int& i_element0, const int& i_element1, const int& i_element2 )
        : m_elements{i_element0, i_element1, i_element2}
    {
        PBR_ASSERT( !HasNans() );
    }

#ifdef PBR_DEBUG
    /// Copy constructor.
    Vec3i( const Vec3i& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( int ) * 3 );
        PBR_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Vec3i& operator=( const Vec3i& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( int ) * 3 );
        PBR_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    inline int& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 3 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    inline const int& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 3 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    inline Vec3i operator+( const Vec3i& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec3i( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] + i_vector.m_elements[ 2 ] );
    }

    /// Addition assignment.
    inline Vec3i& operator+=( const Vec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        return *this;
    }

    /// Subtraction.
    inline Vec3i operator-( const Vec3i& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec3i( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] - i_vector.m_elements[ 2 ] );
    }

    /// Unary negation.
    inline Vec3i operator-() const
    {
        PBR_ASSERT( !HasNans() );
        return Vec3i( -m_elements[ 0 ], -m_elements[ 1 ], -m_elements[ 2 ] );
    }

    inline Vec3i& operator-=( const Vec3i& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        return *this;
    }

    inline Vec3i& operator*=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        return *this;
    }

    inline Vec3i operator/( const int& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        return Vec3i( m_elements[ 0 ] * reciprocal, m_elements[ 1 ] * reciprocal, m_elements[ 2 ] * reciprocal );
    }

    inline Vec3i& operator/=( const int& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        int reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        return *this;
    }
    inline int X() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
    inline int Y() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }
    inline int Z() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }

    /// Comparison operator
    inline bool operator==( const Vec3i& i_vector ) const
    {
        return m_elements[ 0 ] == i_vector.m_elements[ 0 ] && m_elements[ 1 ] == i_vector.m_elements[ 1 ] &&
               m_elements[ 2 ] == i_vector.m_elements[ 2 ];
    }

    /// Not equal operator
    inline bool operator!=( const Vec3i& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    /// Get the number of elements in this vector.
    inline static size_t GetElementSize()
    {
        return 3;
    }

    /// Are any of the element values NaNs?
    inline bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] );
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string ToString() const
    {
        std::stringstream ss;
        ss << "Vec3i( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << ", ";
        ss << m_elements[ 2 ];
        ss << " )";
        return ss.str();
    }

private:
    int m_elements[ 3 ] = {0, 0, 0};
};

inline Vec3i operator*( const Vec3i& i_vector, const int& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec3i( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar, i_vector[ 2 ] * i_scalar );
}

inline Vec3i operator*( const int& i_scalar, const Vec3i& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec3i( i_vector[ 0 ] * i_scalar, i_vector[ 1 ] * i_scalar, i_vector[ 2 ] * i_scalar );
}

PBR_NAMESPACE_END