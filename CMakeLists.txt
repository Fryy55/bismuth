cmake_minimum_required(VERSION 3.31)
project(bismuth VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp

    test/*.cpp
)
if (PROJECT_IS_TOP_LEVEL)
    add_executable(${PROJECT_NAME} ${SOURCES})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
endif()

if (DEFINED BISMUTH_USE_NAMESPACE)
    message(STATUS "BISMUTH_USE_NAMESPACE set. Adding to PCH.")
    target_precompile_headers(${PROJECT_NAME}
        PUBLIC
            pch/namespace.hpp
    )
else()
    message(STATUS "BISMUTH_USE_NAMESPACE not set. Not using the namespace.")
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
)
target_link_libraries(${PROJECT_NAME} dpp)

include("cmake/CPM.cmake")
CPMAddPackage("gh:Fryy55/aurora@1.1.2")
target_link_libraries(${PROJECT_NAME} Aurora)