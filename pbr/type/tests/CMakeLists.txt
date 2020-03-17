file(GLOB CPPFILES *.cpp)
foreach( CPPFILE ${CPPFILES} )
    get_filename_component(TEST_PROGRAM ${CPPFILE} NAME_WE)
    pbr_test_program(${TEST_PROGRAM}
        CPPFILES
            ${CPPFILE}
        LIBRARIES
            pbr_tool
            pbr_type
    )
endforeach( CPPFILE )
