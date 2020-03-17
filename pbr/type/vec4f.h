#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tool/assert.h>

PBR_NAMESPACE_BEGIN

/// \class Vec4f
class PBR_API Vec4f final
{
public:
    using ElementType = float;

    /// Default constructor.
    Vec4f() = default;

    /// Destructor.
    ~Vec4f() = default;

    /// Element-wise constructor.
    explicit Vec4f( const float& i_element0, const float& i_element1, const float& i_element2, const float& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        PBR_ASSERT( !HasNans() );
    }

#ifdef PBR_DEBUG
    /// Copy constructor.
    Vec4f( const Vec4f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 4 );
        PBR_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Vec4f& operator=( const Vec4f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 4 );
        PBR_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    inline float& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 4 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    inline const float& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 4 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    inline Vec4f operator+( const Vec4f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec4f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    /// Addition assignment.
    inline Vec4f& operator+=( const Vec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    /// Subtraction.
    inline Vec4f operator-( const Vec4f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Vec4f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    /// Unary negation.
    inline Vec4f operator-() const
    {
        PBR_ASSERT( !HasNans() );
        return Vec4f( -m_elements[ 0 ], -m_elements[ 1 ], -m_elements[ 2 ], -m_elements[ 3 ] );
    }

    inline Vec4f& operator-=( const Vec4f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    inline Vec4f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    inline Vec4f operator/( const float& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Vec4f( m_elements[ 0 ] * reciprocal,
                      m_elements[ 1 ] * reciprocal,
                      m_elements[ 2 ] * reciprocal,
                      m_elements[ 3 ] * reciprocal );
    }

    inline Vec4f& operator/=( const float& i_scalar )
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
    inline float Z() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }
    inline float W() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }

    /// Comparison operator
    inline bool operator==( const Vec4f& i_vector ) const
    {
        return m_elements[ 0 ] == i_vector.m_elements[ 0 ] && m_elements[ 1 ] == i_vector.m_elements[ 1 ] &&
               m_elements[ 2 ] == i_vector.m_elements[ 2 ] && m_elements[ 3 ] == i_vector.m_elements[ 3 ];
    }

    /// Not equal operator
    inline bool operator!=( const Vec4f& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    /// Get the number of elements in this vector.
    inline static size_t GetElementSize()
    {
        return 4;
    }

    /// Are any of the element values NaNs?
    inline bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] );
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string ToString() const
    {
        std::stringstream ss;
        ss << "Vec4f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << ", ";
        ss << m_elements[ 2 ];
        ss << ", ";
        ss << m_elements[ 3 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 4 ] = {0, 0, 0, 0};
};

inline Vec4f operator*( const Vec4f& i_vector, const float& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec4f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar );
}

inline Vec4f operator*( const float& i_scalar, const Vec4f& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Vec4f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar );
}

PBR_NAMESPACE_END