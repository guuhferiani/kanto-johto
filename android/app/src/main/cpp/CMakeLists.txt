cmake_minimum_required(VERSION 3.22.1)

project("gba-native")

add_library(mgba_libretro SHARED IMPORTED)
set_target_properties(mgba_libretro PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libmgba_libretro.so"
)

add_library(gba-native SHARED
    native-bridge.c
)

find_library(log-lib log)

target_link_libraries(gba-native
    mgba_libretro
    ${log-lib}
)
