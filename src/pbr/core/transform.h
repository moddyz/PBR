#pragma once

/// \file core/transform.h
///
/// Transformation operations.

#include <pbr/pbr.h>
#include <pbr/utils/diagnostic.h>

#include <gm/types/mat4f.h>
#include <gm/types/vec3fRange.h>

#include <gm/functions/inverse.h>
#include <gm/functions/lengthSquared.h>
#include <gm/functions/matrixProduct.h>
#include <gm/functions/setIdentity.h>
#include <gm/functions/setRotate.h>
#include <gm/functions/setRotateX.h>
#include <gm/functions/setRotateY.h>
#include <gm/functions/setRotateZ.h>
#include <gm/functions/setScale.h>
#include <gm/functions/setTranslate.h>
#include <gm/functions/transformPoint.h>
#include <gm/functions/transformVector.h>
#include <gm/functions/transpose.h>

PBR_NS_OPEN

// Forward declarations.
class Transform;

/// \class Transform
///
/// Transform stores 4x4 matrices which linearly map 3 dimensional
/// points, vectors, and normals from one coordinate space (frame) to another.
class Transform
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, setting the matrix and its inverse to the identity element.
    inline Transform()
        : m_matrix( _Identity() )
        , m_inverse( _Identity() )
    {
    }

    /// Constructor with a 4x4 transformation matrix.
    ///
    /// \param i_matrix The 4x4 matrix.
    inline explicit Transform( const gm::Mat4f& i_matrix )
        : m_matrix( i_matrix )
    {
        GM_VERIFY( gm::Inverse( i_matrix, m_inverse ) );
    }

    /// Constructor with a 4x4 transformation matrix, and its inverse.
    ///
    /// \param i_matrix The 4x4 matrix.
    /// \param i_inverse The inverse of \p i_matrix.
    inline explicit Transform( const gm::Mat4f& i_matrix, const gm::Mat4f& i_inverse )
        : m_matrix( i_matrix )
        , m_inverse( i_inverse )
    {
        PBR_ASSERT( gm::MatrixProduct( m_matrix, m_inverse ) == _Identity() );
    }

    // --------------------------------------------------------------------- //
    /// \name Unary operations
    // --------------------------------------------------------------------- //

    /// Get the inverse of this transform.
    ///
    /// \return The inverse transform.
    inline Transform Inverse() const
    {
        return Transform( m_inverse, m_matrix );
    }

    /// Get the transpose of this transform.
    ///
    /// \return The transposed transform.
    inline Transform Transpose() const
    {
        return Transform( gm::Transpose( m_matrix ), gm::Transpose( m_inverse ) );
    }

    // --------------------------------------------------------------------- //
    /// \name Binary operations.
    // --------------------------------------------------------------------- //

    /// Transform composition.
    ///
    /// \param i_rhs The right-hand-side transform.
    ///
    /// \return The composed transformation.
    inline Transform operator*( const Transform& i_rhs ) const
    {
        return Transform( gm::MatrixProduct( m_matrix, i_rhs.m_matrix ),
                          gm::MatrixProduct( i_rhs.m_inverse, m_inverse ) );
    }

    // --------------------------------------------------------------------- //
    /// \name Translate, rotate, scale
    // --------------------------------------------------------------------- //

    /// Create a translation transformation.
    ///
    /// \param i_translate The translate coordinates.
    ///
    /// \return Translation transform.
    static inline Transform Translate( const gm::Vec3f& i_translate )
    {
        gm::Mat4f matrix  = _Identity();
        gm::Mat4f inverse = _Identity();
        gm::SetTranslate( i_translate, matrix );
        gm::SetTranslate( -i_translate, matrix );
        return Transform( matrix, inverse );
    }

    /// Create a scaling transformation.
    ///
    /// \param i_scale The scale coordinates.
    ///
    /// \return Scaling transform.
    static inline Transform Scale( const gm::Vec3f& i_scale )
    {
        gm::Mat4f matrix  = _Identity();
        gm::Mat4f inverse = _Identity();
        gm::SetScale( i_scale, matrix );
        gm::SetScale( gm::Vec3f( 1.0f / i_scale.X(), 1.0f / i_scale.Y(), 1.0f / i_scale.Z() ), inverse );
        return Transform( matrix, inverse );
    }

    /// Create a x-axis rotation transformation.
    ///
    /// \param i_angle The angle in degrees.
    ///
    /// \return The x-axis rotation transformation.
    static inline Transform RotateX( float i_angle )
    {
        gm::Mat4f matrix = _Identity();
        gm::SetRotateX( i_angle, matrix );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Create a y-axis rotation transformation.
    ///
    /// \param i_angle The angle in degrees.
    ///
    /// \return The y-axis rotation transformation.
    static inline Transform RotateY( float i_angle )
    {
        gm::Mat4f matrix = _Identity();
        gm::SetRotateY( i_angle, matrix );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Create a z-axis rotation transformation.
    ///
    /// \param i_angle The angle in degrees.
    ///
    /// \return The y-axis rotation transformation.
    static inline Transform RotateZ( float i_angle )
    {
        gm::Mat4f matrix = _Identity();
        gm::SetRotateZ( i_angle, matrix );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Create a rotation transformation around a specified axis.
    ///
    /// \param i_angle The angle in degrees.
    /// \param i_axis The axis of rotation.
    ///
    /// \return The rotation transform around an arbituary axis.
    static inline Transform Rotate( float i_angle, const gm::Vec3f& i_axis )
    {
        gm::Mat4f matrix = _Identity();
        gm::SetRotate( i_angle, i_axis, matrix );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Check if this transform performs a scale.
    ///
    /// \return If the current transform performs scaling.
    inline bool HasScale() const
    {
        return gm::Vec3f( gm::LengthSquared( gm::TransformVector( m_matrix, gm::Vec3f( 1, 0, 0 ) ) ),
                          gm::LengthSquared( gm::TransformVector( m_matrix, gm::Vec3f( 0, 1, 0 ) ) ),
                          gm::LengthSquared( gm::TransformVector( m_matrix, gm::Vec3f( 0, 0, 1 ) ) ) ) ==
               gm::Vec3f( 1, 1, 1 );
    }

    // --------------------------------------------------------------------- //
    /// \name Transform application
    // --------------------------------------------------------------------- //

    /// Apply the current transform on a vector.
    ///
    /// \param i_vector The vector to transform.
    ///
    /// \return The transformed vector.
    inline gm::Vec3f TransformVector( const gm::Vec3f& i_vector ) const
    {
        return gm::TransformVector( m_matrix, i_vector );
    }

    /// Apply the current transform on a point.
    ///
    /// \param i_point The point to transform.
    ///
    /// \return The transformed point.
    inline gm::Vec3f TransformPoint( const gm::Vec3f& i_point ) const
    {
        return gm::TransformPoint( m_matrix, i_point );
    }

    /// Apply the current transform on a bounding box.
    ///
    /// \param i_bounds The bounding box to transform.
    ///
    /// \return The transformed bounding box.
    inline gm::Vec3fRange TransformBounds( const gm::Vec3fRange& i_bounds ) const
    {
        return gm::Vec3fRange( gm::TransformPoint( m_matrix, i_bounds.Min() ),
                               gm::TransformPoint( m_matrix, i_bounds.Max() ) );
    }

    // --------------------------------------------------------------------- //
    /// \name Utility
    // --------------------------------------------------------------------- //

    /// Get the string representation.  For debugging purposes.
    ///
    /// \return Descriptive string representing this type instance.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "Transform( matrix = ";
        ss << m_matrix.GetString();
        ss << ", inverse = ";
        ss << m_inverse.GetString();
        ss << " )";
        return ss.str();
    }

    /// Check if any the matrix or its inverse have NaN values.
    ///
    /// \retval true If there are NaN values.
    /// \retval false If there are no NaN values.
    inline bool HasNans() const
    {
        return m_matrix.HasNans() || m_inverse.HasNans();
    }

private:
    // Utility to get a 4x4 identity matrix.
    inline static gm::Mat4f _Identity()
    {
        gm::Mat4f matrix;
        gm::SetIdentity( matrix );
        return matrix;
    }

    gm::Mat4f m_matrix;
    gm::Mat4f m_inverse;
};

/// Operator overload for << to enable writing the string representation of \p i_transform into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_transform the source composite value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const Transform& i_transform )
{
    o_outputStream << i_transform.GetString();
    return o_outputStream;
}

PBR_NS_CLOSE
