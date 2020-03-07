set(PACKAGE_NAME "hdPbr")

# Public headers
file(GLOB HEADER_FILES *.h)
file(
    COPY ${HEADER_FILES}
    DESTINATION ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME}
)

# Library.
file(GLOB SRC_FILES *.cpp)
add_library(${PACKAGE_NAME} SHARED ${SRC_FILES})
target_compile_options(${PACKAGE_NAME}
    PRIVATE
        -g -O3 -Wno-deprecated -Werror
)
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_include_directories(${PACKAGE_NAME}
    SYSTEM
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
        ${USD_INCLUDE_DIR}
        ${PYTHON_INCLUDE_DIR}
        ${Boost_INCLUDE_DIR}
        ${TBB_INCLUDE_DIRS}
)
target_link_libraries(${PACKAGE_NAME}
    PRIVATE
        -L${USD_LIBRARY_DIR}
)
target_link_libraries(${PACKAGE_NAME}
    PRIVATE
        ${PYTHON_LIBRARIES}
        ${Boost_LIBRARIES}
        ${TBB_tbb_LIBRARY}
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
    DESTINATION ${CMAKE_INSTALL_PREFIX}/plg/usd/${PACKAGE_NAME}/resources
)

install(TARGETS ${PACKAGE_NAME}
    LIBRARY DESTINATION plg
    ARCHIVE DESTINATION plg
)

