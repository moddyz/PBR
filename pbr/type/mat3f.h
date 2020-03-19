#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tool/almost.h>
#include <pbr/tool/assert.h>

PBR_NAMESPACE_BEGIN

/// \class Mat3f
class PBR_API Mat3f final
{
public:
    using ElementType = float;

    /// Default constructor.
    Mat3f() = default;

    /// Destructor.
    ~Mat3f() = default;

    /// Element-wise constructor.
    explicit Mat3f( const float& i_element0,
                    const float& i_element1,
                    const float& i_element2,
                    const float& i_element3,
                    const float& i_element4,
                    const float& i_element5,
                    const float& i_element6,
                    const float& i_element7,
                    const float& i_element8 )
        : m_elements{i_element0,
                     i_element1,
                     i_element2,
                     i_element3,
                     i_element4,
                     i_element5,
                     i_element6,
                     i_element7,
                     i_element8}
    {
        PBR_ASSERT( !HasNans() );
    }

#ifdef PBR_DEBUG
    /// Copy constructor.
    Mat3f( const Mat3f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 9 );
        PBR_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    Mat3f& operator=( const Mat3f& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( float ) * 9 );
        PBR_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    inline float& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 9 );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    inline const float& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < 9 );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    inline Mat3f operator+( const Mat3f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Mat3f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] + i_vector.m_elements[ 3 ],
                      m_elements[ 4 ] + i_vector.m_elements[ 4 ],
                      m_elements[ 5 ] + i_vector.m_elements[ 5 ],
                      m_elements[ 6 ] + i_vector.m_elements[ 6 ],
                      m_elements[ 7 ] + i_vector.m_elements[ 7 ],
                      m_elements[ 8 ] + i_vector.m_elements[ 8 ] );
    }

    /// Addition assignment.
    inline Mat3f& operator+=( const Mat3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        m_elements[ 4 ] += i_vector.m_elements[ 4 ];
        m_elements[ 5 ] += i_vector.m_elements[ 5 ];
        m_elements[ 6 ] += i_vector.m_elements[ 6 ];
        m_elements[ 7 ] += i_vector.m_elements[ 7 ];
        m_elements[ 8 ] += i_vector.m_elements[ 8 ];
        return *this;
    }

    /// Subtraction.
    inline Mat3f operator-( const Mat3f& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return Mat3f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] - i_vector.m_elements[ 3 ],
                      m_elements[ 4 ] - i_vector.m_elements[ 4 ],
                      m_elements[ 5 ] - i_vector.m_elements[ 5 ],
                      m_elements[ 6 ] - i_vector.m_elements[ 6 ],
                      m_elements[ 7 ] - i_vector.m_elements[ 7 ],
                      m_elements[ 8 ] - i_vector.m_elements[ 8 ] );
    }

    /// Unary negation.
    inline Mat3f operator-() const
    {
        PBR_ASSERT( !HasNans() );
        return Mat3f( -m_elements[ 0 ],
                      -m_elements[ 1 ],
                      -m_elements[ 2 ],
                      -m_elements[ 3 ],
                      -m_elements[ 4 ],
                      -m_elements[ 5 ],
                      -m_elements[ 6 ],
                      -m_elements[ 7 ],
                      -m_elements[ 8 ] );
    }

    inline Mat3f& operator-=( const Mat3f& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        m_elements[ 4 ] -= i_vector.m_elements[ 4 ];
        m_elements[ 5 ] -= i_vector.m_elements[ 5 ];
        m_elements[ 6 ] -= i_vector.m_elements[ 6 ];
        m_elements[ 7 ] -= i_vector.m_elements[ 7 ];
        m_elements[ 8 ] -= i_vector.m_elements[ 8 ];
        return *this;
    }

    inline Mat3f& operator*=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        m_elements[ 4 ] *= i_scalar;
        m_elements[ 5 ] *= i_scalar;
        m_elements[ 6 ] *= i_scalar;
        m_elements[ 7 ] *= i_scalar;
        m_elements[ 8 ] *= i_scalar;
        return *this;
    }

    inline Mat3f operator/( const float& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        return Mat3f( m_elements[ 0 ] * reciprocal,
                      m_elements[ 1 ] * reciprocal,
                      m_elements[ 2 ] * reciprocal,
                      m_elements[ 3 ] * reciprocal,
                      m_elements[ 4 ] * reciprocal,
                      m_elements[ 5 ] * reciprocal,
                      m_elements[ 6 ] * reciprocal,
                      m_elements[ 7 ] * reciprocal,
                      m_elements[ 8 ] * reciprocal );
    }
    inline const float& operator()( size_t i_row, size_t i_column ) const
    {
        return m_elements[ i_row * 3 + i_column ];
    }
    inline float& operator()( size_t i_row, size_t i_column )
    {
        return m_elements[ i_row * 3 + i_column ];
    }

    inline Mat3f& operator/=( const float& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        float reciprocal = 1.0 / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        m_elements[ 3 ] *= reciprocal;
        m_elements[ 4 ] *= reciprocal;
        m_elements[ 5 ] *= reciprocal;
        m_elements[ 6 ] *= reciprocal;
        m_elements[ 7 ] *= reciprocal;
        m_elements[ 8 ] *= reciprocal;
        return *this;
    }

    /// Comparison operator
    inline bool operator==( const Mat3f& i_vector ) const
    {
        return TlAlmostEqual( m_elements[ 0 ], i_vector.m_elements[ 0 ] ) &&
               TlAlmostEqual( m_elements[ 1 ], i_vector.m_elements[ 1 ] ) &&
               TlAlmostEqual( m_elements[ 2 ], i_vector.m_elements[ 2 ] ) &&
               TlAlmostEqual( m_elements[ 3 ], i_vector.m_elements[ 3 ] ) &&
               TlAlmostEqual( m_elements[ 4 ], i_vector.m_elements[ 4 ] ) &&
               TlAlmostEqual( m_elements[ 5 ], i_vector.m_elements[ 5 ] ) &&
               TlAlmostEqual( m_elements[ 6 ], i_vector.m_elements[ 6 ] ) &&
               TlAlmostEqual( m_elements[ 7 ], i_vector.m_elements[ 7 ] ) &&
               TlAlmostEqual( m_elements[ 8 ], i_vector.m_elements[ 8 ] );
    }

    /// Not equal operator
    inline bool operator!=( const Mat3f& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    /// Get the number of elements in this vector.
    inline static size_t GetElementSize()
    {
        return 9;
    }

    /// Are any of the element values NaNs?
    inline bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] ) || std::isnan( m_elements[ 4 ] ) || std::isnan( m_elements[ 5 ] ) ||
               std::isnan( m_elements[ 6 ] ) || std::isnan( m_elements[ 7 ] ) || std::isnan( m_elements[ 8 ] );
    }

    /// Get the string representation.  For debugging purposes.
    inline std::string ToString() const
    {
        std::stringstream ss;
        ss << "Mat3f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << ", ";
        ss << m_elements[ 2 ];
        ss << ", ";
        ss << m_elements[ 3 ];
        ss << ", ";
        ss << m_elements[ 4 ];
        ss << ", ";
        ss << m_elements[ 5 ];
        ss << ", ";
        ss << m_elements[ 6 ];
        ss << ", ";
        ss << m_elements[ 7 ];
        ss << ", ";
        ss << m_elements[ 8 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 9 ] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
};

inline Mat3f operator*( const Mat3f& i_vector, const float& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Mat3f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar,
                  i_vector[ 4 ] * i_scalar,
                  i_vector[ 5 ] * i_scalar,
                  i_vector[ 6 ] * i_scalar,
                  i_vector[ 7 ] * i_scalar,
                  i_vector[ 8 ] * i_scalar );
}

inline Mat3f operator*( const float& i_scalar, const Mat3f& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return Mat3f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar,
                  i_vector[ 4 ] * i_scalar,
                  i_vector[ 5 ] * i_scalar,
                  i_vector[ 6 ] * i_scalar,
                  i_vector[ 7 ] * i_scalar,
                  i_vector[ 8 ] * i_scalar );
}

PBR_NAMESPACE_END