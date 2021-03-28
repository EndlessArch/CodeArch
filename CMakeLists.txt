project(CodeArch)
cmake_minimum_required(VERSION 3.19.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Curses REQUIRED)

file(GLOB SOURCE_FILES
    main.cpp
    src/*.cpp
    )

include_directories(${CURSES_INCLUDE_DIRS})    

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${CURSES_LIBRARIES})

target_link_options(${PROJECT_NAME} PUBLIC -fcoroutines-ts)

message(STATUS "Curse include directories:" ${CURSES_INCLUDE_DIR})
message(STATUS "Curse libraries:" ${CURSES_LIBRARIES})