cmake_minimum_required( VERSION 3.0 )

project( lab3 )

# flags

# include files
include_directories( ./include ./src )

# target
add_executable( main ./src/main.cpp ./src/matrix.cpp ./src/sqlite3.c)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries (
    
    main

    ${CMAKE_CURRENT_SOURCE_DIR}/libs/sqlite3.lib
    ${CMAKE_DL_LIBS}
    Threads::Threads
)