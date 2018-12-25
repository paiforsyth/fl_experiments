# CMake 3.5.1+ is recommended
cmake_minimum_required(VERSION 3.6.1)
# C++ 11 is required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myProject project.cpp)

find_package(ArrayFire REQUIRED)
# ...

find_package(flashlight REQUIRED)
# ...

target_link_libraries(
  myProject
  PRIVATE
  ArrayFire::afcuda
  flashlight::flashlight # assumes flashlight was built with the CUDA backend
)
