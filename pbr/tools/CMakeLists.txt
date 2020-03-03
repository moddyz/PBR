set(PACKAGE_NAME "tools")
file(GLOB CPPFILES *.cpp)
file(GLOB HEADERS *.h)
pbr_library(${PACKAGE_NAME}
    CPPFILES
        ${CPPFILES}
    HEADERS
        ${HEADERS}
    LIBRARIES
        dl
)

add_subdirectory(tests)
