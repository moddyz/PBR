#pragma once

/// \file core/transform.h
///
/// Transformation operations.

#include <pbr/pbr.h>

#include <gm/types/mat4f.h>
#include <gm/types/vec3fRange.h>

#include <gm/functions/invert.h>
#include <gm/functions/setIdentity.h>
#include <gm/functions/setRotate.h>
#include <gm/functions/setRotateX.h>
#include <gm/functions/setRotateY.h>
#include <gm/functions/setRotateZ.h>
#include <gm/functions/setScale.h>
#include <gm/functions/setTranslate.h>
#include <gm/functions/transformBounds.h>
#include <gm/functions/transformPoint.h>
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

    /// Constructor with a 4x4 transformation matrix.
    ///
    /// \param i_matrix The 4x4 matrix.
    inline explicit Transform( const gm::Mat4f& i_matrix )
        : m_matrix( i_matrix )
        , m_inverse( gm::Invert( i_matrix ) )
    {
    }

    /// Constructor with a 4x4 transformation matrix, and its inverse.
    ///
    /// \param i_matrix The 4x4 matrix.
    /// \param i_inverse The inverse of \p i_matrix.
    inline explicit Transform( const gm::Mat4f& i_matrix, const gm::Mat3f& i_inverse )
        : m_matrix( i_matrix )
        , m_inverse( i_inverse )
    {
        PBR_ASSERT( gm::MatrixProduct( m_matrix, m_inverse ) == Identity() );
    }

    // --------------------------------------------------------------------- //
    /// \name Representation
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
    /// \name Translate, rotate, scale
    // --------------------------------------------------------------------- //

    /// Create a translation transformation.
    ///
    /// \param i_translate The translate coordinates.
    ///
    /// \return Translation transform.
    static inline Transform Translate( const gm::Vec3f& i_translate )
    {
        gm::Mat4f matrix  = Identity();
        gm::Mat4f inverse = Identity();
        gm::SetTranslate( matrix, i_translate );
        gm::SetTranslate( inverse, -i_translate );
        return Transform( matrix, inverse );
    }

    /// Create a scaling transformation.
    ///
    /// \param i_scale The scale coordinates.
    ///
    /// \return Scaling transform.
    static inline Transform Scale( const gm::Vec3f& i_scale )
    {
        gm::Mat4f matrix  = Identity();
        gm::Mat4f inverse = Identity();
        gm::SetScale( matrix, i_scale );
        gm::SetScale( inverse, gm::Vec3f( 1.0f / i_scale.X(), 1.0f / i_scale.Y(), 1.0f / i_scale.Z() ) );
        return Transform( matrix, inverse );
    }

    /// Create a x-axis rotation transformation.
    ///
    /// \param i_angle The angle in degrees.
    ///
    /// \return The x-axis rotation transformation.
    static inline Transform RotateX( float i_angle )
    {
        gm::Mat4f matrix = Identity();
        gm::SetRotateX( matrix, i_angle );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Create a y-axis rotation transformation.
    ///
    /// \param i_angle The angle in degrees.
    ///
    /// \return The y-axis rotation transformation.
    static inline Transform RotateY( float i_angle )
    {
        gm::Mat4f matrix = Identity();
        gm::SetRotateY( matrix, i_angle );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Create a z-axis rotation transformation.
    ///
    /// \param i_angle The angle in degrees.
    ///
    /// \return The y-axis rotation transformation.
    static inline Transform RotateZ( float i_angle )
    {
        gm::Mat4f matrix = Identity();
        gm::SetRotateZ( matrix, i_angle );
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
        gm::Mat4f matrix = Identity();
        gm::SetRotate( matrix, i_angle, i_axis );
        return Transform( matrix, gm::Transpose( matrix ) );
    }

    /// Check if this transform performs a scale.
    ///
    /// \return If the current transform performs scaling.
    inline bool HasScale() const
    {
        return gm::Vec3f( gm::LengthSquared( gm::TransformVector( gm::Vec3f( 1, 0, 0 ) ) ),
                          gm::LengthSquared( gm::TransformVector( gm::Vec3f( 0, 1, 0 ) ) ),
                          gm::LengthSquared( gm::TransformVector( gm::Vec3f( 0, 0, 1 ) ) ) ) == gm::Vec3f( 1, 1, 1 );
    }

    // --------------------------------------------------------------------- //
    /// \name Transform application
    // --------------------------------------------------------------------- //

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

    /// Get a 4x4 identity matrix.
    ///
    /// \return 4x4 identity matrix.
    inline static gm::Mat4f Identity()
    {
        gm::Mat4f matrix;
        gm::SetIdentity( matrix );
        return matrix;
    }

private:
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
