set(PACKAGE_PREFIX "pbr")
add_subdirectory(platform)
add_subdirectory(tools)
add_subdirectory(types)
add_subdirectory(functions)

# Top level headers.
file(GLOB HEADERS *.h)
file(
    COPY ${HEADERS}
    DESTINATION ${CMAKE_BINARY_DIR}/include/${PACKAGE_PREFIX}
)

install(
    FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PACKAGE_PREFIX}
)
