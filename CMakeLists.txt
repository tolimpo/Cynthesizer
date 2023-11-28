cmake_minimum_required(VERSION 3.16)
project(Cynthesizer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/libsoundio)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR}/lib/libsoundio/libsoundio.a)
message(${PROJECT_BINARY_DIR})


