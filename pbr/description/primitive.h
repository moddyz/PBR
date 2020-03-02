#pragma once

namespace pbr
{

class Primitive
{
public:
    Primitive() = default;
    virtual ~Primitive() = default;

    /// Primitive cannot be copied.
    Primitive( const Primitive& ) = delete;
    Primitive& operator=( const Primitive& ) = delete;
};

}
