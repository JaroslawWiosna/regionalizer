#
#  @file CMakeLists.txt
# 
#  @author Jaroslaw Wiosna
# 
#  @par Licence
#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

cmake_minimum_required (VERSION 2.6)

option(SANITIZER "Address Sanitizer" OFF)
option(BUILD_TESTS "Build tests" ON)
#option(BUILD_LONG_RUNNING_TESTS "Build long running tests" OFF)
option(BUILD_LONG_RUNNING_TESTS "Build tests" OFF)

#set(CMAKE_CXX_STANDARD 17)
set(COMPILE_FLAGS "--std=gnu++17 -Wall -Wno-missing-braces -fconcepts --coverage -g -O3 -fprofile-arcs -ftest-coverage")
set(GTEST_FLAGS "-lgtest")
set(LINK_FLAGS "-lpthread")

#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#  set(COMPILE_FLAGS  "${COMPILE_FLAGS} -stdlib=libstdc++")
#endif()

if(BUILD_TESTS)
  set(LINK_FLAGS "${GTEST_FLAGS} ${LINK_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )

include_directories( 
  City
  VectorOfCities
  FlagParser 
  DatabaseReader 
  GnuplotHandler
  ClosestCity
)
set(files
  City/City.cpp
  VectorOfCities/VectorOfCities.cpp
  FlagParser/FlagParser.cpp
  DatabaseReader/DatabaseReader.cpp
  GnuplotHandler/GnuplotHandler.cpp
  ClosestCity/ClosestCity.cpp
)

######

  SET(RESOURCE_COMPILER xxd)
  SET(INPUT_FILE "../help.txt")
  SET(OUTPUT_FILE ${INPUT_FILE}.hpp)
  #  ADD_CUSTOM_COMMAND(
  #    OUTPUT ${OUTPUT_FILE}.test
  #    COMMAND rm -f help.txt.hpp
  #    COMMENT "Removing ${OUTPUT_FILE}")
  ADD_CUSTOM_COMMAND(
    OUTPUT ${OUTPUT_FILE}
    COMMAND ${RESOURCE_COMPILER} -i ${INPUT_FILE} ${OUTPUT_FILE}
    COMMENT "Compiling ${INPUT_FILE} (text file) to ${OUTPUT_FILE}")
  LIST(APPEND COMPILED_RESOURCES ${OUTPUT_FILE})

######

project (regionalizer)
add_executable(regionalizer main.cpp ${files} ${COMPILED_RESOURCES}) 
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(regionalizer gtest pthread stdc++fs)

enable_testing()

if(BUILD_TESTS)
	add_subdirectory(regionalizerTests)
endif()


