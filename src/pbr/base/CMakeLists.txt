file(GLOB HEADERS *.h)
file(GLOB CPPFILES *.cpp)

cpp_library(pbr_base
    TYPE
        SHARED
    HEADERS_INSTALL_PREFIX
        ${ROOT_PREFIX}/base
    PUBLIC_HEADERS
        ${HEADERS}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        backward
        dl
        dw
)

