set(PROGRAM_NAME "toolsTest")
file(GLOB CPPFILES *.cpp)
pbr_program(${PROGRAM_NAME}
    CPPFILES
        ${CPPFILES}
    LIBRARIES
        pbr_tools
)
