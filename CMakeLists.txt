cmake_minimum_required(VERSION 3.2)

project(LidarTools)

include_directories(
	.
)

if(CMAKE_CURRENT_LIST_DIR STREQUAL CMAKE_SOURCE_DIR)
	add_executable(testIntensity
		test/intensity2RGB.cpp
	)

	target_link_libraries(testIntensity
		LidarTools
	)
endif()

add_library(${PROJECT_NAME}
		LidarDataParser.c
		LidarIntensity2RGB.c
)
