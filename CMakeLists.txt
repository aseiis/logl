# CMakeList.txt : CMake project for logl_cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("logl")

if(WIN32)
	set(GLFW_DIR $ENV{GLFW_DIR})
	include_directories("${GLFW_DIR}/include")
	link_directories("${GLFW_DIR}/lib-vc2022")
else()
	find_package(glfw3 3.3 REQUIRED)
endif()


add_executable(logl src/main.cpp src/glad.c)

if(WIN32)
	target_link_libraries(logl glfw3)
else()
	target_link_libraries(logl glfw)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET logl PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
