cmake_minimum_required( VERSION 3.0 )

project( lab8 )

# flags

# include files
include_directories( ./include ./src )

# target
add_executable( main ./src/main.cpp ./src/philosopher.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(main PRIVATE Threads::Threads)
