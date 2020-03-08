set(PACKAGE_PREFIX "pbr")
add_subdirectory(tools)
add_subdirectory(types)
add_subdirectory(functions)

file(
    COPY "api.h"
    DESTINATION ${CMAKE_BINARY_DIR}/include/${PACKAGE_PREFIX}
)

install(
    FILES "api.h"
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PACKAGE_PREFIX}
)
