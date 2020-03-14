set(PACKAGE_NAME "function")
file(GLOB CPPFILES *.cpp)
file(GLOB HEADERS *.h)
pbr_library(${PACKAGE_NAME}
    CPPFILES
        ${CPPFILES}
    HEADERS
        ${HEADERS}
    LIBRARIES
        pbr_tool
        pbr_type
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
