# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/novaTentativaDriver_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/novaTentativaDriver_autogen.dir/ParseCache.txt"
  "novaTentativaDriver_autogen"
  )
endif()
