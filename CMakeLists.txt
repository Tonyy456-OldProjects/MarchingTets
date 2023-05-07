cmake_minimum_required(VERSION 3.11)
 
# ================= Set library directores. Expecially for qt and VTK =======================
set(Qt5_DIR "/usr/local/Cellar/qt@5/5.15.8_3/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH "/Users/ajdalesandro/local/VTK-9.2.6")

# ================= Set Project Name =======================
project(MarchingTets) # sets PROJECT_NAME as well

# ================= Find VTK Packages.=======================
find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

# ================= Make Sure Packages are found =======================
if (NOT VTK_FOUND)
    message(FATAL_ERROR "${PROJECT_NAME}: Unable to find the VTK build folder.")
endif()
if (NOT QT5_FOUND AND NOT DEFINED Qt5_DIR)
    message(FATAL_ERROR "${PROJECT_NAME}: Unable to find the QT5 build folder. Set it's path")
endif()

#  ============= Set src files =======================
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(${PROJECT_NAME} 
    src/CylinderExample.cxx 
)

# ================ Link Libraries ======================= 
target_link_libraries(${PROJECT_NAME} 
    PRIVATE ${VTK_LIBRARIES}
)

# ================ VTK auto initialization is needed  ======================= 
vtk_module_autoinit(
  TARGETS ${PROJECT_NAME} 
  MODULES ${VTK_LIBRARIES}
)

# =========== INSTALL COMMAND for makefile ===========
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin)
install(TARGETS ${PROJECT_NAME} 
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
)
