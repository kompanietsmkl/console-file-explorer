cmake_minimum_required(VERSION 3.10)
project(FileExplorer)

set(CMAKE_CXX_STANDARD 17)

# Pointing to header files
include_directories(include)

# Pointing to cpp files from src/ and main.cpp
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    main.cpp
)

# Creating an executable
add_executable(file_explorer ${SRC_FILES})
