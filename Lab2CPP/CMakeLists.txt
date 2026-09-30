add_executable(JollyScript
        interpreter.cpp
        helpers.h
        helpers.cpp
)

target_include_directories(JollyScript PUBLIC ../LibraryCPP)
target_link_libraries(JollyScript LibraryCPP)