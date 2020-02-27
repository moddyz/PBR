set(PACKAGE_NAME "pbrt")

# Public headers
file(GLOB PUBLIC_HEADERS *.h)
file(
    COPY ${PUBLIC_HEADERS} 
    DESTINATION ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}
)
install(
    FILES ${PUBLIC_HEADERS}    
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PACKAGE_NAME}
)

# Library.
file(GLOB SRC_FILES *.cpp)
add_library(${PACKAGE_NAME} SHARED ${SRC_FILES})
target_include_directories(${PACKAGE_NAME} 
    PUBLIC 
        $<INSTALL_INTERFACE:/include>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
        ${LLVM_INCLUDES}
)
target_link_libraries(${PACKAGE_NAME} 
    PUBLIC 
        ar
        arch
        sdf
        trace
        plug
        tf
        vt
        gf
        glf
        work
        hf
        hd
        hdx
)

install(TARGETS ${PACKAGE_NAME}
    EXPORT ${PACKAGE_NAME}-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
