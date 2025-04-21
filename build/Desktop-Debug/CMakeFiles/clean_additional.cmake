# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\fileEncryption_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\fileEncryption_autogen.dir\\ParseCache.txt"
  "fileEncryption_autogen"
  )
endif()
