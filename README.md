# MarchingTets
![GitHub contributors](https://img.shields.io/github/contributors/Tonyy456/MarchingTets?color=09903F&style=plastic)
![GitHub top language](https://img.shields.io/github/languages/top/Tonyy456/MarchingTets?style=plastic)
![GitHub commit activity](https://img.shields.io/github/commit-activity/y/Tonyy456/MarchingTets?label=Commits)
</br>
A repo that intends to build on previous Marching Tetrahedrons research

# ⚡Install Software
1. download cmake
```sh
brew install cmake
cmake --version
```

2. Download VTK. I recommend going onto their website and downloading and compiling their .tar  
zsh/macos
```sh
brew install vtk
```

3. Download Qt5
```sh
brew install qt@5
ls /usr/local/Cellar/qt@5
# Note installation directory
```

4. Update CMakeLists.txt
```cmake
set(Qt5_DIR "<qt5_build_dir>/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH "<vtk_build_dir>")
```

