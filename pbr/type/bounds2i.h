#pragma once

#include <sstream>

#include <pbr/api.h>

#include <pbr/type/vec2i.h>

#include <limits>

PBR_NAMESPACE_BEGIN

/// \class Bounds2i
class PBR_API Bounds2i final
{
public:
    /// Default constructor.
    Bounds2i() = default;

    /// Destructor.
    ~Bounds2i() = default;

    /// Element-wise constructor.
    explicit Bounds2i( const Vec2i& i_min, const Vec2i& i_max )
        : m_min( i_min )
        , m_max( i_max )
    {
    }

    /// Const accessor for "min".
    const Vec2i& Min() const
    {
        return m_min;
    }

    /// Mutable accessor for "min".
    Vec2i& Min()
    {
        return m_min;
    }

    /// Const accessor for "max".
    const Vec2i& Max() const
    {
        return m_max;
    }

    /// Mutable accessor for "max".
    Vec2i& Max()
    {
        return m_max;
    }

    /// Get the string representation.  For debugging purposes.
    std::string ToString()
    {
        std::stringstream ss;
        ss << "Bounds2i( ";
        ss << m_min.ToString();
        ss << ", ";
        ss << m_max.ToString();
        ss << " )";
        return ss.str();
    }

private:
    /// Element members.
    Vec2i m_min = Vec2i( std::numeric_limits< int >::max(), std::numeric_limits< int >::max() );
    Vec2i m_max = Vec2i( std::numeric_limits< int >::min(), std::numeric_limits< int >::min() );
};

PBR_NAMESPACE_END