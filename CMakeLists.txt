cmake_minimum_required(VERSION 3.10)
project(striboh)

set(CMAKE_CXX_STANDARD 17)
set(MSGPACK_CXX17 ON)
add_definitions("-std=c++17")
enable_testing()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(FetchContent)
###############################################################################
# SML begin
FetchContent_Declare(sml
        PREFIX ${CMAKE_SOURCE_DIR}/src/main/cpp/sml
        URL https://raw.githubusercontent.com/boost-ext/sml/master/include/boost/sml.hpp
        DOWNLOAD_NO_EXTRACT true
        )
FetchContent_GetProperties(sml)
if(NOT sml_POPULATED)
    FetchContent_Populate(sml)
    # Copy an additional/replacement file into the populated source
    file(COPY ${CMAKE_SOURCE_DIR}/src/main/cpp/sml/src/sml.hpp DESTINATION
            ${CMAKE_SOURCE_DIR}/src/main/cpp/sml)
endif()
# SML end
###############################################################################

###############################################################################
# DI begin
FetchContent_Declare(di
        PREFIX ${CMAKE_SOURCE_DIR}/src/main/cpp/di
        URL https://raw.githubusercontent.com/boost-ext/di/cpp14/include/boost/di.hpp
        DOWNLOAD_NO_EXTRACT true
        )
FetchContent_GetProperties(di)
if(NOT di_POPULATED)
    FetchContent_Populate(di)
    # Copy an additional/replacement file into the populated source
    file(COPY ${CMAKE_SOURCE_DIR}/src/main/cpp/di/src/di.hpp DESTINATION
            ${CMAKE_SOURCE_DIR}/src/main/cpp/di)
endif()
# SML end
###############################################################################


set(STRIBOH_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp)
set(STRIBOH_LIBS boost_log boost_filesystem boost_program_options boost_system boost_thread fmt pthread ${CMAKE_DL_LIBS})

add_subdirectory(src/main/cpp/striboh)
add_subdirectory(src/test/cpp)
add_subdirectory(src/test/echo)
# and this adds the doxygen folder as a CMake subdirectory.
add_subdirectory(doxygen)
