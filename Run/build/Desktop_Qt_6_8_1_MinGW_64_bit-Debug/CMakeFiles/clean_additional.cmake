# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Run_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Run_autogen.dir\\ParseCache.txt"
  "Run_autogen"
  )
endif()
