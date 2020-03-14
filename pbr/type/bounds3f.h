#pragma once

#include <sstream>

#include <pbr/api.h>

#include <pbr/type/vec3f.h>

#include <limits>

PBR_NAMESPACE_BEGIN

/// \class Bounds3f
class PBR_API Bounds3f final
{
public:
    /// Default constructor.
    Bounds3f() = default;

    /// Destructor.
    ~Bounds3f() = default;

    /// Element-wise constructor.
    explicit Bounds3f( const Vec3f& i_min, const Vec3f& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    const Vec3f& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    Vec3f& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    const Vec3f& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    Vec3f& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    std::string ToString()
    {
        std::stringstream ss;
        ss << "Bounds3f( ";
        ss << m_min.ToString();
        ss << ", ";
        ss << m_max.ToString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec3f m_min = Vec3f( std::numeric_limits< float >::max(),
                         std::numeric_limits< float >::max(),
                         std::numeric_limits< float >::max() );
    Vec3f m_max = Vec3f( std::numeric_limits< float >::min(),
                         std::numeric_limits< float >::min(),
                         std::numeric_limits< float >::min() );
};
}
;

PBR_NAMESPACE_END