#pragma once

#include <cmath>
#include <cstring>

#include <pbr/api.h>
#include <pbr/tools/assert.h>

PBR_NAMESPACE_BEGIN

/// \class {{ obj.className }}
class PBR_API {{ obj.className }} final
{
public:
    using ElementType = {{ obj.scalarType }};

    /// Default constructor.
    {{ obj.className }}()  = default;

    /// Destructor.
    ~{{ obj.className }}() = default;

    /// Element-wise constructor.
    explicit {{ obj.className }}(
{% for index in range(obj.elementSize) -%}
        const {{ obj.scalarType }}& i_element{{ index }}
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
    )
        : m_elements{
{% for index in range(obj.elementSize) -%}
        i_element{{ index }}
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif -%}
{%- endfor %}
        }
    {
        PBR_ASSERT( !HasNans() );
    }

    /// Copy constructor.
    {{ obj.className }}( const {{ obj.className }}& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( {{ obj.scalarType }}  )* {{ obj.elementSize }} );
    }

    /// Copy assignment operator.
    {{ obj.className }}& operator=( const {{ obj.className }}& i_vector )
    {
        PBR_ASSERT( !HasNans() );
        std::memcpy( ( void* ) m_elements, ( const void* ) i_vector.m_elements, sizeof( {{ obj.scalarType }}  )* {{ obj.elementSize }} );
        return *this;
    }

    /// Element-wise index read accessor.
    {{ obj.scalarType }}& operator[]( size_t i_index )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < {{ obj.elementSize }} );
        return m_elements[ i_index ];
    }

    /// Element-wise index write accessor.
    const {{ obj.scalarType }}& operator[]( size_t i_index ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_index < {{ obj.elementSize }} );
        return m_elements[ i_index ];
    }

    //
    // Arithmetic Operator Overloading.
    //

    {{ obj.className }} operator+( const {{ obj.className }}& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return {{ obj.className }}(
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] + i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    {{ obj.className }}& operator+=( const {{ obj.className }}& i_vector )
    {
        PBR_ASSERT( !HasNans() );
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] += i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    {{ obj.className }} operator-( const {{ obj.className }}& i_vector ) const
    {
        PBR_ASSERT( !HasNans() );
        return {{ obj.className }}(
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] - i_vector.m_elements[ {{ index }} ]
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    {{ obj.className }}& operator-=( const {{ obj.className }}& i_vector )
    {
        PBR_ASSERT( !HasNans() );
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] -= i_vector.m_elements[ {{ index }} ];
{%- endfor %}
        return *this;
    }

    {{ obj.className }} operator*( const {{ obj.scalarType }}& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        return {{ obj.className }}(
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] * i_scalar
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

    {{ obj.className }}& operator*=( const {{ obj.scalarType }}& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] *= i_scalar;
{%- endfor %}
        return *this;
    }

    //
    // Arithmetic Operator Overloading.
    //

    {{ obj.className }} operator/( const {{ obj.scalarType }}& i_scalar ) const
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        {{ obj.scalarType }} reciprocal = 1.0 / i_scalar;
        return {{ obj.className }}(
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] * reciprocal
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
        );
    }

{%- if obj.dims|length == 2 -%}
    const {{ obj.scalarType }}& operator()( size_t i_row, size_t i_column ) const
    {
        return m_elements[ i_row * {{ obj.dims[ 0 ] }} + i_column ];
    }
{%- endif %}

    {{ obj.className }}& operator/=( const {{ obj.scalarType }}& i_scalar )
    {
        PBR_ASSERT( !HasNans() );
        PBR_ASSERT( i_scalar != 0.0 );
        {{ obj.scalarType }} reciprocal = 1.0 / i_scalar;
{% for index in range(obj.elementSize) -%}
        m_elements[ {{ index }} ] *= reciprocal;
{%- endfor %}
        return *this;
    }

{%- if obj.dims|length == 1 and obj.elementSize <= 4 -%}
    {{ obj.scalarType }} X() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 0 ];
    }
{%- endif %}

{%- if obj.dims|length == 1 and obj.elementSize >= 2 and obj.elementSize <= 4 -%}
    {{ obj.scalarType }} Y() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 1 ];
    }
{%- endif %}

{%- if obj.dims|length == 1 and obj.elementSize >= 3 and obj.elementSize <= 4 -%}
    {{ obj.scalarType }} Z() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 2 ];
    }
{%- endif %}

{%- if obj.dims|length == 1 and obj.elementSize == 4 %}
    {{ obj.scalarType }} W() const
    {
        PBR_ASSERT( !HasNans() );
        return m_elements[ 3 ];
    }
{%- endif %}

    /// Get the number of elements in this vector.
    static size_t GetElementSize()
    {
        return {{ obj.elementSize }};
    }

    /// Are any of the element values NaNs?
    bool HasNans() const
    {
        return
{% for index in range(obj.elementSize) -%}
        std::isnan( m_elements[ {{ index }} ] )
{%- if index + 1 < obj.elementSize -%}
        ||
{%- endif %}
{%- endfor %}
        ;
    }

private:
    {{ obj.scalarType }} m_elements[ {{ obj.elementSize }} ] = {
{%- for index in range(obj.elementSize) -%}
        0
{%- if index + 1 < obj.elementSize -%}
        ,
{%- endif %}
{%- endfor %}
    };
};
PBR_NAMESPACE_END
