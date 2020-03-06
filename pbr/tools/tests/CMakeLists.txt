pbr_program(testAssert
    CPPFILES
        testAssert.cpp
    LIBRARIES
        pbr_tools
)

pbr_program(testProfile
    CPPFILES
        testProfile.cpp
    LIBRARIES
        pbr_tools
        pthread
)

pbr_program(testLog
    CPPFILES
        testLog.cpp
    LIBRARIES
        pbr_tools
)
