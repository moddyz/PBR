set(PACKAGE_NAME "tool")
file(GLOB CPPFILES *.cpp)
file(GLOB HEADERS *.h)
pbr_library(${PACKAGE_NAME}
    CPPFILES
        ${CPPFILES}
    HEADERS
        ${HEADERS}
    LIBRARIES
        pbr_platform
        dl
        dw
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
