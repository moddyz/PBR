#pragma once

#include <sstream>

#include <pbr/api.h>

#include <pbr/type/vec3i.h>

#include <limits>

PBR_NAMESPACE_BEGIN

/// \class Bounds3i
class PBR_API Bounds3i final
{
public:
    /// Default constructor.
    Bounds3i() = default;

    /// Destructor.
    ~Bounds3i() = default;

    /// Element-wise constructor.
    explicit Bounds3i( const Vec3i& i_min, const Vec3i& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    const Vec3i& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    Vec3i& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    const Vec3i& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    Vec3i& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    std::string ToString()
    {
        std::stringstream ss;
        ss << "Bounds3i( ";
        ss << m_min.ToString();
        ss << ", ";
        ss << m_max.ToString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec3i m_min = Vec3i( std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max(),
                         std::numeric_limits< int >::max() );
    Vec3i m_max = Vec3i( std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min(),
                         std::numeric_limits< int >::min() );
};

PBR_NAMESPACE_END