cmake_minimum_required(VERSION 3.6...3.31)

project(rmgr-nsfr CXX)

option(RMGR_NSFR_BUILD_TESTS "Whether to build rmgr::nsfr's unit tests" OFF)

if (MSVC OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    list(APPEND RMGR_NSFR_COMPILE_OPTIONS "/W4")
elseif (CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
    list(APPEND RMGR_NSFR_COMPILE_OPTIONS "-Wall")
endif()

set(RMGR_NSFR_FILES
    src/nsfr.cpp
    include/rmgr/nsfr.h
)

source_group("Source Files" FILES ${RMGR_NSFR_FILES})

add_library(rmgr-nsfr STATIC ${RMGR_NSFR_FILES})

target_include_directories(rmgr-nsfr PUBLIC "include")
target_compile_options(rmgr-nsfr PRIVATE ${RMGR_NSFR_COMPILE_OPTIONS})

if (RMGR_NSFR_BUILD_TESTS)
    add_subdirectory(tests)
    set_directory_properties(PROPERTIES VS_STARTUP_PROJECT rmgr-nsfr-tests)
endif()
