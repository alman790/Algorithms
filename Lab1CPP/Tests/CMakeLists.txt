add_executable(MyTestLab1CPP tests.cpp)

add_test(
        NAME MyTestLab1CPP
        COMMAND MyTestLab1CPP
        $<TARGET_FILE:Task1>
        $<TARGET_FILE:Task2>
)

set_tests_properties( MyTestLab1CPP PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )