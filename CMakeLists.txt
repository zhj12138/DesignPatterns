cmake_minimum_required(VERSION 3.16)
project(Learn)

set(CMAKE_CXX_STANDARD 17)

macro(add_directory_executable DIR_NAME)
    aux_source_directory(${DIR_NAME} ${DIR_NAME}_SRC)
    add_executable(${DIR_NAME} ${${DIR_NAME}_SRC})
endmacro()

add_subdirectory(CreationalPatterns)
add_subdirectory(StructuralPatterns)
add_subdirectory(BehavioralPatterns)