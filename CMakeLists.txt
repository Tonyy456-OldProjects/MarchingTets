cmake_minimum_required (VERSION 3.0)

project(VtkJpegViewer)

set(CMAKE_PREFIX_PATH "C:/Path/To/vtk-6.3.0")

find_package(VTK 6 REQUIRED)

include(${VTK_USE_FILE})

add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/lenna.jpg ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>
)
