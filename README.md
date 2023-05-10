# Marching Tetrahedrons

Marching Tetrahedrons is a technique used in computer graphics to render 3D models. It involves constructing tetrahedrons from adjacent data points in a volumetric data set, and using these tetrahedrons to determine if a point is inside or outside a solid. The marching tetrahedrons algorithm is typically used to create a surface mesh that represents the surface of the solid. This technique has applications beyond computer graphics, particularly in the field of medical imaging. To improve upon previous research there are a few direction I am trying to explore, such as improving the speed of the algorithm, using neural networks to optimize the placement and configuration of tetrahedrons, and/or applying the technique to medical imaging data.

![GitHub pull requests](https://img.shields.io/github/issues-pr/Tonyy456/MarchingTets?color=5579c6&style=plastic)
![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed/Tonyy456/MarchingTets?color=C07B3A&style=plastic)
![GitHub contributors](https://img.shields.io/github/contributors/Tonyy456/MarchingTets?color=09903F&style=plastic)
![GitHub top language](https://img.shields.io/github/languages/top/Tonyy456/MarchingTets?style=plastic)
![GitHub commit activity](https://img.shields.io/github/commit-activity/y/Tonyy456/MarchingTets?label=Commits)
</br>

## Preview
[insert screenshots of project]

## Software Used
* CMake version 3.11
* VTK version 9.2.6
* Qt5 version 5.15.8

## Features
#### CMakeCompile.sh
 > This is a bash script that compiles all the software and calls the compiled makefile as well.
[insert key things that this software does]

## Installation and Usage
1. Install required software.
2. Update CMakeLists.txt
```cmake
set(Qt5_DIR "<qt5_build_dir>/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH "<vtk_build_dir>")
```

3. Use the makefile for shortcuts
```sh
make
make run
```
## Contact Information
[insert contact information]
