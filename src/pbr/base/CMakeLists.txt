file(GLOB HEADERS *.h)
file(GLOB CPPFILES *.cpp)
cpp_library("platform"
    HEADER_INSTALL_PREFIX
        ${ROOT_PREFIX}
    HEADERS
        ${HEADERS}
    CPPFILES
        ${CPPFILES}
)
