cmake_minimum_required( VERSION 3.0 )

project( lab3 )

# flags

# include files
include_directories( ./include ./src )

# target
add_executable( main ./src/main.cpp ./src/matrix.cpp )

# 3rd party libs
