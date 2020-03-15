#pragma once

#include <cmath>
#include <cstring>
#include <sstream>

#include <pbr/api.h>
#include <pbr/tool/assert.h>

PBR_NAMESPACE_BEGIN

/// \class {{ context.className }}
class PBR_API {{ context.className }} final
{
public:
    using ElementType = {{ context.elementType.className }};

    /// Default constructor.
    {{ context.className }}()  = default;

    /// Destructor.
    ~{{ context.className }}() = default;

    /// Element-wise constructor.
    explicit {{ context.className }}(
{% for index in range(context.elementSize) -%}
        const {{ context.elementType.className }}& i_element{{ index }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
        : m_elements{
{% for index in range(context.elementSize) -%}
        i_element{{ index }}
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
        }
    {
        PBR_ASSERT( !HasNans() );
    }

#ifdef PBR_DEBUG
    /// Copy constructor.
    {{ context.className }}( const {{ context.className }}& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( {{ context.elementType.className }}  )* {{ context.elementSize }} );
        PBR_ASSERT( !HasNans() );
    }

    /// Copy assignment operator.
    {{ context.className }}& operator=( const {{ context.className }}& i_vector )
    {
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( {{ context.elementType.className }}  )* {{ context.elementSize }} );
        PBR_ASSERT( !HasNans() );
        return *this;
    }
#endif

    /// Element-wise index read accessor.
    {{ context.elementType.className }}& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < {{ context.elementSize }} );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    const {{ context.elementType.className }}& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < {{ context.elementSize }} );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    {{ context.className }} operator+( const {{ context.className }}& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] + i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Addition assignment.
    {{ context.className }}& operator+=( const {{ context.className }}& i_vector )
    {
        PBR_ASSERT( !HasNans() );
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] += i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    /// Subtraction.
    {{ context.className }} operator-( const {{ context.className }}& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] - i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    /// Unary negation.
    {{ context.className }} operator-() const
    {
        PBR_ASSERT( !HasNans() );
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        -m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    {{ context.className }}& operator-=( const {{ context.className }}& i_vector )
    {
        PBR_ASSERT( !HasNans() );
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] -= i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    {{ context.className }}& operator*=( const {{ context.elementType.className }}& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] *= i_scalar;
{%- endfor %}
        return *this;
    }

    {{ context.className }} operator/( const {{ context.elementType.className }}& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        {{ context.elementType.className }} reciprocal = 1.0 / i_scalar;
        return {{ context.className }}(
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] * reciprocal
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

{%- if context.dims|length == 2 -%}
    const {{ context.elementType.className }}& operator()( size_t i_row, size_t i_column ) const
    {
        return m_elements[ i_row * {{ context.dims[ 0 ] }} + i_column ];
    }
{%- endif %}

    {{ context.className }}& operator/=( const {{ context.elementType.className }}& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        {{ context.elementType.className }} reciprocal = 1.0 / i_scalar;
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] *= reciprocal;
{%- endfor %}
        return *this;
    }

{%- if context.dims|length == 1 and context.elementSize <= 4 -%}
    {{ context.elementType.className }} X() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
{%- endif %}

{%- if context.dims|length == 1 and context.elementSize >= 2 and context.elementSize <= 4 -%}
    {{ context.elementType.className }} Y() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }
{%- endif %}

{%- if context.dims|length == 1 and context.elementSize >= 3 and context.elementSize <= 4 -%}
    {{ context.elementType.className }} Z() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }
{%- endif %}

{%- if context.dims|length == 1 and context.elementSize == 4 %}
    {{ context.elementType.className }} W() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }
{%- endif %}

    /// Comparison operator
    bool operator==( const {{context.className}}& i_vector ) const
    {
        return
{% for index in range(context.elementSize) -%}
        m_elements[ {{ index }} ] == i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < context.elementSize -%}
        &&
{% endif %}
{%- endfor -%}
        ;
    }

    /// Get the number of elements in this vector.
    static size_t GetElementSize()
    {
        return {{ context.elementSize }};
    }

    /// Are any of the element values NaNs?
    bool HasNans() const
    {
        return
{% for index in range(context.elementSize) -%}
        std::isnan( m_elements[ {{ index }} ] )
{%- if index + 1 < context.elementSize -%}
        ||
{%- endif %}
{%- endfor %}
        ;
    }

    /// Get the string representation.  For debugging purposes.
    std::string ToString()
    {
        std::stringstream ss;
        ss << "{{ context.className }}( ";
{%- for index in range(context.elementSize) -%}
        ss << m_elements[ {{ index }} ];
{%- if index + 1 < context.elementSize -%}
        ss << ", ";
{%- endif %}
{%- endfor %}
        ss << " )";
        return ss.str();
    }

private:
    {{ context.elementType.className }} m_elements[ {{ context.elementSize }} ] = {
{%- for index in range(context.elementSize) -%}
        0
{%- if index + 1 < context.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
    };
};

{{ context.className }} operator*( const {{ context.className }}& i_vector, const {{ context.elementType.className }}& i_scalar )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return {{ context.className }}(
{% for index in range(context.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < context.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

{{ context.className }} operator*( const {{ context.elementType.className }}& i_scalar, const {{ context.className }}& i_vector )
{
    PBR_ASSERT( !i_vector.HasNans() );
    return {{ context.className }}(
{% for index in range(context.elementSize) -%}
    i_vector[ {{ index }} ] * i_scalar
{%- if index + 1 < context.elementSize -%}
    ,
{%- endif %}
{%- endfor %}
    );
}

PBR_NAMESPACE_END
