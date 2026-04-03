cmake_minimum_required(VERSION 4.1)
project(sortKey C)

set(CMAKE_C_STANDARD 23)

add_executable(sortKey main.c
        vector/vector.c
        vector/vector.h
        utils/utils.c
        utils/utils.h
        solution/solution.c
        solution/solution.h
        vector/item.c
        vector/item.h)
