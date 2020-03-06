#include <pbr/tools/assert.h>

int main()
{
    PBR_ASSERT( false );
    PBR_ASSERT_MSG( false, "Failure!!!!%s", "HAHA" );
}
