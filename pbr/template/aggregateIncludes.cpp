{% for path in context.includePaths -%}
#include <{{ path }}>
{% endfor %}
