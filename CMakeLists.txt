cmake_minimum_required(VERSION 3.16)
project(Cynthesizer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/external/libsoundio)
add_subdirectory(lib/external/elements)


#message("CMAKE_INSTALL_BINDIR: " ${CMAKE_INSTALL_BINDIR})


add_executable(${CMAKE_PROJECT_NAME} main.cpp)


set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE C
        COMPILE_FLAGS "-std=c99 -Wall")
target_link_libraries(${CMAKE_PROJECT_NAME} libsoundio_shared)
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(${CMAKE_PROJECT_NAME} elements)


#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE libsoundio_static)
#target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/lib/libsoundio)
#target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC soundio)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/external/libsoundio/soundio)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/external/elements/lib/include)


