# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\labtrack_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\labtrack_autogen.dir\\ParseCache.txt"
  "labtrack_autogen"
  )
endif()
