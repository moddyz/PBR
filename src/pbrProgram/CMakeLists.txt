get_filename_component(PROGRAM_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
cpp_program(
    ${PROGRAM_NAME}
    CPPFILES
        main.cpp
    LIBRARIES
        pbr_utils
        pbr_core
        cxxopts
)
