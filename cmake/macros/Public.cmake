function(pbr_library PACKAGE_NAME)

    set(options
    )

    set(oneValueArgs
    )

    set(multiValueArgs
        CPPFILES
        HEADERS
        INCLUDE_PATHS
        LIBRARIES
    )

    cmake_parse_arguments(args
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN}
    )

    set(PACKAGE_PATH ${PACKAGE_PREFIX}/${PACKAGE_NAME})
    set(PACKAGE_TARGET ${PACKAGE_PREFIX}_${PACKAGE_NAME})

    # Public headers
    file(
        COPY ${args_HEADERS}
        DESTINATION ${CMAKE_BINARY_DIR}/include/${PACKAGE_PATH}
    )
    install(
        FILES ${args_HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PACKAGE_PATH}
    )

    # Library.
    add_library(${PACKAGE_TARGET} SHARED ${args_CPPFILES})

    target_compile_options(${PACKAGE_TARGET}
        PRIVATE
            -g -O3 -Wno-deprecated -Werror
    )

    target_include_directories(${PACKAGE_TARGET}
        PUBLIC
            $<INSTALL_INTERFACE:/include>
            $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
        PRIVATE
            ${args_INCLUDE_PATHS}
    )

    target_link_libraries(${PACKAGE_TARGET}
        PRIVATE ${args_LIBRARIES}
    )

    install(TARGETS ${PACKAGE_TARGET}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )

endfunction() # pbr_library

function(pbr_program PROGRAM_NAME)

    set(options
    )

    set(oneValueArgs
    )

    set(multiValueArgs
        CPPFILES
        INCLUDE_PATHS
        LIBRARIES
    )

    cmake_parse_arguments(args
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN}
    )

    add_executable(${PROGRAM_NAME} ${args_CPPFILES})

    target_compile_options(${PROGRAM_NAME}
        PRIVATE
            -g -O3 -Wno-deprecated -Werror
    )

    target_include_directories(${PROGRAM_NAME}
        PRIVATE
            $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
            ${args_INCLUDE_PATHS}
    )

    target_link_libraries(
        ${PROGRAM_NAME} PRIVATE ${args_LIBRARIES}
    )

    if (LINUX)
        set_target_properties(${PROGRAM_NAME} PROPERTIES LINK_FLAGS "-Wl,-rpath,$ORIGIN/../lib/")
    endif()

    if (APPLE)
        set_target_properties(${PROGRAM_NAME} PROPERTIES LINK_FLAGS "-Wl,-rpath,@executable_path/../lib/")
    endif()

    # Install
    install(
        TARGETS ${PROGRAM_NAME}
        DESTINATION bin
    )

endfunction() # pbr_program


