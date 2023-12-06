cmake_minimum_required(VERSION 3.16)
project(Cynthesizer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/external/RtAudio)
add_subdirectory(lib/external/Tonic)
add_subdirectory(lib/external/elements)




#message("CMAKE_INSTALL_BINDIR: " ${CMAKE_INSTALL_BINDIR})


add_executable(${CMAKE_PROJECT_NAME} main.cpp
        lib/include/Cynthesizer.h
        lib/include/Cynthesizer.h
        lib/src/Cynthesizer.cpp
        lib/src/Cynthesizer.cpp
        lib/include/SoundOutput.h
        lib/src/SoundOutput.cpp)


#set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
#        LINKER_LANGUAGE C
#        COMPILE_FLAGS "-std=c99 -Wall")
#target_link_libraries(${CMAKE_PROJECT_NAME} libsoundio_shared)
#install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(${CMAKE_PROJECT_NAME} rtaudio)
target_link_libraries(${CMAKE_PROJECT_NAME} Tonic)
target_link_libraries(${CMAKE_PROJECT_NAME} elements)


#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE libsoundio_static)
#target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/lib/libsoundio)
#target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC soundio)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/external/RtAudio)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/external/Tonic/src)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/external/elements/lib/include)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)

#include(${CMAKE_SOURCE_DIR}/lib/external/elements/cmake/AppIcon.cmake)
#include(${CMAKE_SOURCE_DIR}/lib/external/elements/cmake/ElementsConfigApp.cmake)


