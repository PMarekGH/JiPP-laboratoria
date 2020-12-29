cmake_minimum_required( VERSION 3.0 )

project( lab7 )

# flags

# include files
include_directories( ./include ./src )

# target
add_executable( main ./src/main.cpp ./src/employee.cpp ./src/HRMS.cpp )

# 3rd party libs
