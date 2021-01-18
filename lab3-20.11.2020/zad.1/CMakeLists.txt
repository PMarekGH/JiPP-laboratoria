cmake_minimum_required( VERSION 3.0 )

project( lab3 )

# flags

# include files
include_directories( ./include ./src )

# target
add_executable( main ./src/main.cpp ./src/matrix.cpp ./src/sqlite3.c)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(dl)
target_link_libraries(main PRIVATE Threads::Threads)
target_link_libraries(main ${CMAKE_DL_LIBS})