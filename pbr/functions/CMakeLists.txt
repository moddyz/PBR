set(PACKAGE_NAME "functions")
file(GLOB CPPFILES *.cpp)
file(GLOB HEADERS *.h)
pbr_library(${PACKAGE_NAME}
    CPPFILES
        ${CPPFILES}
    HEADERS
        ${HEADERS}
    LIBRARIES
        pbr_tools
        pbr_types
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
