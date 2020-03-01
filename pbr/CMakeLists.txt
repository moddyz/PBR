set(PACKAGE_NAME "pbr")

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
    INTERFACE 
        $<INSTALL_INTERFACE:/include>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
)

install(TARGETS ${PACKAGE_NAME}
    EXPORT ${PACKAGE_NAME}-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
