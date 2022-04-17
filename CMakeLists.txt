cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(OpenGL_GL_PREFERENCE LEGACY)

project(Opengl_Boilerplate VERSION 1.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_definitions("-Wall -Wextra")

add_executable(
	Opengl_Boilerplate 
	main.cpp
	src/window.cpp
	test/test.cpp)

target_include_directories(
	Opengl_Boilerplate 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/test/
	)

message("OpenGL - ${OPENGL_FOUND}: ${OPENGL_LIBRARIES}")
message("GLEW - ${GLEW_FOUND}: ${GLEW_LIBRARIES}")
message("glfw3 - ${GLFW3_FOUND}: ${GLFW3_LIBRARIES}")

target_link_libraries(Opengl_Boilerplate ${GLEW_LIBRARIES} /lib/libglfw.so ${OPENGL_LIBRARIES})