project(01_img_scaling)
add_executable(${PROJECT_NAME} 01_main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} quality_lib)
target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_SOURCE_DIR}/src/quality_assessment")
