project(03_color_spaces)
add_executable(${PROJECT_NAME} 03_main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} quality_lib)
target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_SOURCE_DIR}/src/quality_assessment")
