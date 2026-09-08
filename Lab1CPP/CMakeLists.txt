add_executable(Task1
        task1_main.cpp
        task1.cpp
        helpers.cpp
)

target_include_directories(Task1 PUBLIC ../LibraryCPP)
target_link_libraries(Task1 LibraryCPP)

add_executable(Task2
        task2_main.cpp
        task2.cpp
        helpers.cpp
)

target_include_directories(Task2 PUBLIC ../LibraryCPP)
target_link_libraries(Task2 LibraryCPP)

add_subdirectory(Tests)