CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

PROJECT (v8-vtune-plugin)

set (CMAKE_CXX_STANDARD 11)

SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../out)

ADD_LIBRARY (v8-vtune-plugin SHARED
	../src/libvtune.cc
	../src/vtuneapi.cc
)
