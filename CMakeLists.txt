cmake_minimum_required(VERSION 3.2)

project(LidarTools)

include_directories(
	.
)

if(CMAKE_CURRENT_LIST_DIR STREQUAL CMAKE_SOURCE_DIR)
	add_executable(testIndensity
		test/indensity2RGB.c
	)

	target_link_libraries(testIndensity
		LidarTools
	)
endif()

add_library(${PROJECT_NAME}
		LidarDataParser.c
		LidarIndensity2RGB.c
)