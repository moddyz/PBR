file(GLOB HEADERS *.h)
file(GLOB CPPFILES *.cpp)
get_filename_component(LIBRARY_SUFFIX ${CMAKE_CURRENT_SOURCE_DIR} NAME)

cpp_library(${ROOT_PREFIX}_${LIBRARY_SUFFIX}
    TYPE
        SHARED
    HEADERS_INSTALL_PREFIX
        ${ROOT_PREFIX}/${LIBRARY_SUFFIX}
    PUBLIC_HEADERS
        ${HEADERS}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        ${ROOT_PREFIX}_utils
        ${ROOT_PREFIX}_core
        gm
)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
