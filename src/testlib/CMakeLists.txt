project(testlib)

file(GLOB _src *.h *.cpp)
add_library(${PROJECT_NAME} SHARED ${_src})

target_compile_definitions(${PROJECT_NAME} PRIVATE TESTLIB_LIBRARY)

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>)