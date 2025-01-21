# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LoginTest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LoginTest_autogen.dir\\ParseCache.txt"
  "LoginTest_autogen"
  )
endif()
