set(PACKAGE_NAME "hdPbrt")

# Public headers
file(GLOB PUBLIC_HEADERS *.h)
file(
    COPY ${PUBLIC_HEADERS} 
    DESTINATION ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}
)

# Library.
file(GLOB SRC_FILES *.cpp)
add_library(${PACKAGE_NAME} SHARED ${SRC_FILES})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_include_directories(${PACKAGE_NAME} 
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
        ${USD_INCLUDE_DIR}
        ${PYTHON_INCLUDE_DIR}
        ${Boost_INCLUDE_DIR}
        ${TBB_INCLUDE_DIRS}
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

# PlugInfo.
install(
    FILES plugInfo.json
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/usd/${PACKAGE_NAME}/resources
)

install(TARGETS ${PACKAGE_NAME}
    EXPORT ${PACKAGE_NAME}-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(EXPORT ${PACKAGE_NAME}-targets
    FILE
        ${PACKAGE_NAME}Targets.cmake
    DESTINATION
        ${CMAKE_INSTALL_PREFIX}/cmake/${PACKAGE_NAME}
)
