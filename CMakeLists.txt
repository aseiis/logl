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

# Set a preprocessor definition with the project root path
add_definitions(-DPROJECT_ROOT_PATH="${CMAKE_SOURCE_DIR}/")

add_executable(logl "src/main.cpp" "src/glad.c" "src/Shader.cpp" "headers/utils.h" "vendor/stb_image.h" "vendor/stb_image_implementation.cpp" "headers/Texture.h" "src/Texture.cpp")

if(WIN32)
	target_link_libraries(logl glfw3)
else()
	target_link_libraries(logl glfw)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET logl PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
