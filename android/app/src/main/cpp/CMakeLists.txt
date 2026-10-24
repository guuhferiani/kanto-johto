cmake_minimum_required(VERSION 3.22.1)

project("gba-native")

add_library(gba-native SHARED
    native-bridge.c
)

find_library(log-lib log)

target_link_libraries(gba-native
    ${log-lib}
    dl
)
