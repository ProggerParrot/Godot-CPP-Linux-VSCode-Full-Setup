cmake_minimum_required(VERSION 3.13)
project(example_player)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)


set(GODOT_HEADERS "~/GodotBindings/godot-headers")
set(GODOT_BINDINGS_INCLUDE "~/GodotBindings/include")
set(GODOT_BINDINGS_INCLUDE_GEN "~/GodotBindings/include/gen")
set(GODOT_BINDINGS_INCLUDE_CORE "~/GodotBindings/include/core")
set(GODOT_BINDINGS_LIB_DEBUG "~/GodotBindingd/lib/libgodot-cpp.linux.debug.64.a")
set(GODOT_BINDINGS_LIB_RELEASE "~/GodotBindings/lib/libgodot-cpp.linux.release.64.a")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Build type: Debug")
    set(EXAMPLE_LIB gdnative-example-debug)
    set(GODOT_BINDINGS_LIB ${GODOT_BINDINGS_LIB_DEBUG})
else()
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "Build type: Release")
    set(EXAMPLE_LIB gdnative-example-release)
    set(GODOT_BINDINGS_LIB ${GODOT_BINDINGS_LIB_RELEASE})
endif(CMAKE_BUILD_TYPE MATCHES Debug)

set(
    SRC_FILES
    GodotLibrary.cpp
    Player.cpp
    Root.cpp
)

set(
    HDR_FILES
    Player.h
    Root.h
)

add_library(
    ${EXAMPLE_LIB}
    ${SRC_FILES}
    ${HDR_FILES}
)

target_include_directories(
    ${EXAMPLE_LIB} 
    PRIVATE ${GODOT_HEADERS}
    PRIVATE ${GODOT_BINDINGS_INCLUDE}
    PRIVATE ${GODOT_BINDINGS_INCLUDE_GEN}
    PRIVATE ${GODOT_BINDINGS_INCLUDE_CORE}
)

target_link_directories(
    ${EXAMPLE_LIB}
    PRIVATE ${GODOT_BINDINGS_LIB}
)

target_link_libraries(
    ${EXAMPLE_LIB}
    ${GODOT_BINDINGS_LIB}
)