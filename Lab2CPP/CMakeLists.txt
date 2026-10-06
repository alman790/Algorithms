add_executable(JollyScript
        interpreter.cpp
        interpreter.h
        helpers.h
        helpers.cpp
        main.cpp
)

target_include_directories(JollyScript PUBLIC ../LibraryCPP)
target_link_libraries(JollyScript LibraryCPP)

add_subdirectory(Tests)