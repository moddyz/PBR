set(PACKAGE_NAME "type")
file(GLOB CPPFILES *.cpp)
file(GLOB HEADERS *.h)
pbr_library(${PACKAGE_NAME}
    CPPFILES
        ${CPPFILES}
    HEADERS
        ${HEADERS}
    LIBRARIES
        pbr_tool
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
