cmake_minimum_required(VERSION 3.22.1)

project("gba-native")

add_library(mgba_libretro_android SHARED IMPORTED)
set_target_properties(mgba_libretro_android PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/mgba_libretro_android.so"
)

add_library(gba-native SHARED
    native-bridge.c
)

find_library(log-lib log)

target_link_libraries(gba-native
    mgba_libretro_android
    ${log-lib}
)
