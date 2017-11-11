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

project(FlagParser)

file(GLOB src
  "*.cpp"
  "../../FlagParser/FlagParser.cpp"
)

add_executable(${PROJECT_NAME} ${src} )

set(LINK_FLAGS "stdc++fs ${LINK_FLAGS}")

target_link_libraries(
  ${PROJECT_NAME} 
  ${LINK_FLAGS}
)


add_test(${PROJECT_NAME} ${PROJECT_NAME})
