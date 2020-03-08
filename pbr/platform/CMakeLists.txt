set(PACKAGE_NAME "platform")
file(GLOB HEADERS *.h)
file(GLOB CPPFILES *.cpp)
pbr_library(${PACKAGE_NAME}
    HEADERS
        ${HEADERS}
    CPPFILES
        ${CPPFILES}
)
