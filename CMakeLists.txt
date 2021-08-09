cmake_minimum_required(VERSION 3.10)

project(libaa_plugin)

add_subdirectory(JUCE EXCLUDE_FROM_ALL)
add_subdirectory(libaa EXCLUDE_FROM_ALL)

add_subdirectory(gain)

