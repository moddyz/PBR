{% for path in obj.includePaths -%}
#include <{{ path }}>
{% endfor %}
