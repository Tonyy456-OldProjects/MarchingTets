cmake_minimum_required(VERSION 3.11)
 
# ================= Set Project Name =======================
if (NOT DEFINED PROJECT_NAME)
    message(FATAL_ERROR "PPROJECT_NAME not set")
endif()
project(${PROJECT_NAME}) # sets PROJECT_NAME as well

# ================= Set library directores. Expecially for qt and VTK =======================
set(Qt5_DIR ${MY_Qt5})
set(CMAKE_PREFIX_PATH ${MY_VTK})

# ================= Find VTK Packages.=======================
find_package(VTK REQUIRED COMPONENTS 
  CommonColor
  CommonCore
  FiltersCore
  FiltersSources
  InfovisCore
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  ViewsQt
  GUISupportQt
  RenderingQt
)

# ================= Make Sure Packages are found =======================
if (NOT VTK_FOUND)
    message(FATAL_ERROR "${PROJECT_NAME}: Unable to find the VTK build folder.")
endif()
if(NOT(TARGET VTK::GUISupportQt))
    message(FATAL_ERROR "MinimalQtVTKApp: VTK not built with Qt support.")
endif()
if(NOT DEFINED VTK_QT_VERSION)
  set(VTK_QT_VERSION 5)
endif()
if (NOT QT5_FOUND AND NOT DEFINED Qt5_DIR)
    message(FATAL_ERROR "${PROJECT_NAME}: Unable to find the QT5 build folder. Set it's path")
endif()

set(qt_components Core Gui Widgets)
if(${VTK_QT_VERSION} VERSION_GREATER_EQUAL 6)
  list(APPEND qt_components OpenGLWidgets)
endif()
list(SORT qt_components)
# We have ui files, so this will also bring in the macro:
#   qt5_wrap_ui or qt_wrap_ui from Widgets.
find_package(Qt${VTK_QT_VERSION} QUIET
  REQUIRED COMPONENTS ${qt_components}
)
foreach(_qt_comp IN LISTS qt_components)
  list(APPEND qt_modules "Qt${VTK_QT_VERSION}::${_qt_comp}")
endforeach()
message (STATUS "VTK_VERSION: ${VTK_VERSION}, Qt Version: ${Qt${VTK_QT_VERSION}Widgets_VERSION}")

# Instruct CMake to run moc and uic automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#file(GLOB_RECURSE UI_FILES src/**/*.ui)
#file(GLOB_RECURSE QT_WRAP src/**/*.h)
#file(GLOB_RECURSE CXX_FILES src/**/*.cxx)

file(GLOB_RECURSE UI_FILES "src" "*.ui")
file(GLOB_RECURSE QT_WRAP "src" "*.h")
file(GLOB_RECURSE CXX_FILES "src" "*.cxx")

#  ============= Set src files =======================
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(${PROJECT_NAME} 
  ${CXX_FILES} ${UISrcs} ${QT_WRAP}
)
#target_compile_definitions(${PROJECT_NAME} PRIVATE USE_SCREEN_SIZE)

if (Qt${VTK_QT_VERSION}Widgets_VERSION VERSION_LESS "5.11.0")
  qt5_use_modules(${PROJECT_NAME} ${qt_components})
else()
  target_link_libraries(${PROJECT_NAME} ${qt_modules})
endif()

# ================ Link Libraries ======================= 
target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})

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
