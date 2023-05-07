# MarchingTets
![GitHub contributors](https://img.shields.io/github/contributors/Tonyy456/MarchingTets?color=09903F&style=plastic)
![GitHub top language](https://img.shields.io/github/languages/top/Tonyy456/MarchingTets?style=plastic)
![GitHub commit activity](https://img.shields.io/github/commit-activity/y/Tonyy456/MarchingTets?label=Commits)
</br>
A repo that intends to build on previous Marching Tetrahedrons research

## ⚡Install Software
to build and run the application, you will need the following
* CMake (version 3.11 or later)
* VTK (version 9.2.6 or later)
* Qt5 (version 5.15.8 or later

## 🌟Running the Project
1. Update CMakeLists.txt
```cmake
set(Qt5_DIR "<qt5_build_dir>/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH "<vtk_build_dir>")
```

2. Use the makefile for shortcuts
```sh
make
make run
```

