add_executable(MyTestLab2 tests.cpp)

add_test(
        NAME MyTestLab2
        COMMAND MyTestLab2 $<TARGET_FILE:JollyScript>
)

set_tests_properties( MyTestLab2 PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )