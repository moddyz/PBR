#include <pbr/tools/log.h>

int main()
{
    PBR_LOG_INFO( "foo\n" );
    PBR_LOG_INFO( "foo %s\n", "bar" );
}
