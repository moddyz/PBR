set(PACKAGE_PREFIX "pbr")
add_subdirectory(platform)
add_subdirectory(tool)
add_subdirectory(type)
add_subdirectory(function)

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
