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
option(BUILD_TESTS "Build tests" OFF)
#option(BUILD_LONG_RUNNING_TESTS "Build long running tests" OFF)
option(BUILD_LONG_RUNNING_TESTS "Build tests" OFF)

set(COMPILE_FLAGS "-std=c++1z -Wall -O2 -Wno-missing-braces -ftest-coverage -fprofile-arcs")
set(GTEST_FLAGS "-lgtest")
set(LINK_FLAGS "-lpthread")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(COMPILE_FLAGS  "${COMPILE_FLAGS} -stdlib=libstdc++")
endif()

if(BUILD_TESTS)
  set(LINK_FLAGS "${GTEST_FLAGS} ${LINK_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )

include_directories( 
  src/City
  src/Coordinate
  src/Latitude
  src/Longitude
  src/Region
)
set(files
  src/City/City.cpp
  src/cities.cpp
  src/Coordinate/Coordinate.cpp
  src/Latitude/Latitude.cpp
  src/Longitude/Longitude.cpp
  src/Region/Region.cpp
)

######

project (regionalizer)
#add_executable(regionalizer src/main.cpp ${files} ${COMPILED_RESOURCES}) 
add_executable(regionalizer src/main.cpp ${files}) 
target_link_libraries(regionalizer gtest pthread stdc++fs)




