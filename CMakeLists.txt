cmake_minimum_required(VERSION 3.13)
project(21sh C)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

set(CMAKE_C_STANDARD 99)

find_package(curses REQUIRED)

file(GLOB_RECURSE INC_LIB ./libft/includes/*.h)
file(GLOB_RECURSE INC_PROJ ./includes/*.h)
file(GLOB_RECURSE C_LIB ./libft/source/*.c)
file(GLOB_RECURSE C_PROJ ./source/*.c)

set(INC ${INC_LIB} ${INC_PROJ})
set(SRC ${C_PROJ} ${C_LIB})

HEADER_DIRECTORIES(HD)
include_directories(${HD})

add_executable(21sh ${INC} ${SRC})
target_link_libraries(21sh ${CURSES_LIBRARIES})
