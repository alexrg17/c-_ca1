cmake_minimum_required(VERSION 3.27)
project(cpp_ca1)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_ca1 main.cpp
        bug.cpp
        bug.h
        hopper.cpp
        hopper.h
        crawler.cpp
        crawler.h
        cell.cpp
        cell.h
        board.cpp
        board.h
        PerimeterCrawler.cpp
        PerimeterCrawler.h
)
