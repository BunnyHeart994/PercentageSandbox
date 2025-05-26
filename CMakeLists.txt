cmake_minimum_required(VERSION 4.0.2)
project(PercentageSandbox VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_SHARED_LIBS "Build dynamically" ON)

# Path-storing variables
set(BUILD_DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/build_dependencies")

# PercentageSandbox (.exe)
add_executable(PercentageSandbox "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_include_directories(PercentageSandbox PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
# Adding headers to PercentageSandbox
target_sources(PercentageSandbox PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/libraries.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/macros.h")

# boxdrawer (.dll)
if(BUILD_SHARED_LIBS)
	add_library(boxdrawer SHARED "${BUILD_DEPENDENCIES_DIR}/src/box_drawer.cpp")
else()
	add_library(boxdrawer STATIC "${BUILD_DEPENDENCIES_DIR}/src/box_drawer.cpp")
endif()
target_include_directories(boxdrawer PUBLIC "${BUILD_DEPENDENCIES_DIR}/include")

# Adding headers to boxdrawer
target_sources(boxdrawer PUBLIC "${BUILD_DEPENDENCIES_DIR}/include/box_drawer.h")

# Set DLL's compile options
target_compile_options(boxdrawer PRIVATE -O2)

# Set DLL's compile definitions (macros)
if(BUILD_SHARED_LIBS)
	target_compile_definitions(boxdrawer PUBLIC EXPORT_DLL)
else()
	target_compile_definitions(boxdrawer PUBLIC DEFINE_STATIC)
endif()
	
# Set main executable's compile options, and definitions
target_compile_options(PercentageSandbox PRIVATE -O2)
if(BUILD_SHARED_LIBS)
	target_compile_definitions(PercentageSandbox PRIVATE IMPORT_DLL)
else()	
	target_compile_definitions(PercentageSandbox PRIVATE DEFINE_STATIC)
endif()

# Link main executable with DLL
target_link_libraries(PercentageSandbox PRIVATE boxdrawer)

# Install
install(TARGETS PercentageSandbox boxdrawer
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib)