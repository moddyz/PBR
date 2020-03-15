#pragma once

#include <vector>

{% if context.elementType.isVector %}
#include <pbr/type/{{ context.elementType.headerFileName }}>
{%- endif %}

PBR_NAMESPACE_BEGIN

using {{ context.className }} = std::vector< {{ context.elementType.className }} >;

PBR_NAMESPACE_END

