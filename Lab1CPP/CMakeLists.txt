add_executable(Lab1CPP
        main.cpp
        helpers.h
        helpers.cpp
        task1.h
        task1.cpp
        task2.cpp
        task2.h
)
target_include_directories(Lab1CPP PUBLIC ../LibraryCPP)
target_link_libraries(Lab1CPP LibraryCPP)

add_test(NAME TestLab1CPP COMMAND Lab1CPP)
add_subdirectory(Tests)