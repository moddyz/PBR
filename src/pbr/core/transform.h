#pragma once

/// \file core/transform.h
///
/// Transformation operations.

#include <pbr/pbr.h>

#include <gm/types/mat4f.h>
#include <gm/types/vec3fRange.h>

#include <gm/functions/invert.h>
#include <gm/functions/setIdentity.h>
#include <gm/functions/transformBounds.h>
#include <gm/functions/transformPoint.h>

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

    /// Explicit constructor with a 4x4 transformation matrix.
    ///
    /// \param i_matrix The 4x4 matrix.
    inline explicit Transform( const gm::Mat4f& i_matrix )
        : m_matrix( i_matrix )
        , m_inverse( gm::Invert( i_matrix ) )
    {
    }

    /// Explicit constructor with a 4x4 transformation matrix, and its inverse.
    ///
    /// \param i_matrix The 4x4 matrix.
    /// \param i-inverse The inverse of \p i_matrix.
    inline explicit Transform( const gm::Mat4f& i_matrix, const gm::Mat3f& i_inverse )
        : m_matrix( i_matrix )
        , m_inverse( i_inverse )
    {
        PBR_ASSERT( gm::MatrixProduct( m_matrix, m_inverse ) == Identity() );
    }

    // --------------------------------------------------------------------- //
    /// \name Constants
    // --------------------------------------------------------------------- //

    /// Get a 4x4 identity matrix.
    ///
    /// \return 4x4 identity matrix.
    inline static gm::Mat4f Identity()
    {
        gm::Mat4f matrix;
        gm::SetIdentity( matrix );
        return matrix;
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
    gm::Mat4f m_matrix;
    gm::Mat4f m_inverse;
};

PBR_NS_CLOSE
