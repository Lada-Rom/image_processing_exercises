project(quality_lib LANGUAGES CXX)
add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} PUBLIC
	quality.hpp
)
