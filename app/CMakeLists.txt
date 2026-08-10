cmake_minimum_required(VERSION 3.22)
project("standoff2hook")

add_library(nativehook SHARED
    src/main/jni/nativehook.c
)

target_include_directories(nativehook PRIVATE
    src/main/jni
)

target_compile_definitions(nativehook PRIVATE -DANDROID)
