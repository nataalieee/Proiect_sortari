cmake_minimum_required(VERSION 4.1)
project(Proiect_sortari)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proiect_sortari main.cpp
        sortari/merge_sort.h
        sortari/heap_sort.h
        sortari/radix_sort.h
        sortari/bubble_sort.h
        sortari/insertion_sort.h
        sortari/quick_sort.h)
