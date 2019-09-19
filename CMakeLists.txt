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

set(COMPILE_FLAGS "-std=c++1z -Wall -O2 -Wno-missing-braces")
set(LINK_FLAGS "-lpthread")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(COMPILE_FLAGS  "${COMPILE_FLAGS} -stdlib=libstdc++")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )

include_directories( 
)
set(files
)

######

project (regionalizer)
#add_executable(regionalizer src/main.cpp ${files} ${COMPILED_RESOURCES}) 
add_executable(regionalizer src/main.cpp ${files}) 
target_link_libraries(regionalizer pthread stdc++fs)




