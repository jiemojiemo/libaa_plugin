cmake_minimum_required(VERSION 3.10)

project(libaa_plugin)

set(JUCE_SOURCE_DIR "/Users/user/Documents/develop/JUCE")
set(LIBAA_SOURCE_DIR "/Users/user/Documents/develop/libaa")

add_subdirectory(${JUCE_SOURCE_DIR} ${CMAKE_BINARY_DIR}/juce)
add_subdirectory(${LIBAA_SOURCE_DIR} ${CMAKE_BINARY_DIR}/libaa)

add_subdirectory(gain)

