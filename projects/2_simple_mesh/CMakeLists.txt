cmake_minimum_required(VERSION 3.11)
 
# ================= Set library directores. Expecially for qt and VTK =======================
set(Qt5_DIR "/usr/local/Cellar/qt@5/5.15.8_3/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH "/Users/ajdalesandro/local/VTK-9.2.6")

# ================= Set Project Name =======================
if (NOT DEFINED PROJECT_NAME)
    message(FATAL_ERROR "PPROJECT_NAME not set")
endif()
project(${PROJECT_NAME}) # sets PROJECT_NAME as well


# ================= Find VTK Packages.=======================
find_package(VTK REQUIRED COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersGeneral
  IOXML
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
    src/MarchingTets.cpp
    src/mtMesh.cpp
    src/WindowProcedure.cpp
    src/ApplicationWindow.cpp
)
#target_compile_definitions(${PROJECT_NAME} PRIVATE USE_SCREEN_SIZE)

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
if(DEFINED MT_BIN_DIR)
    install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION ${MT_BIN_DIR}
    )
endif()
