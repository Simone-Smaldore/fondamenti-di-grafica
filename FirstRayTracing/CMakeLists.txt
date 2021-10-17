cmake_minimum_required(VERSION 3.20)
project(FirstRayTracing)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(FirstRayTracing ${SDL2_INCLUDE_DIRS})

add_executable(FirstRayTracing main.cpp utilitySDL/utilitySDL.h utilitySDL/utilitySDL.cpp gradient/gradient.cpp gradient/gradient.h utilitySDL/utilitySDLInline.h flyngBox/flyngBox.cpp flyngBox/flyngBox.h constants.h utilitySDL/vec3.h utilitySDL/point3d.h utilitySDL/ray.h rayTracing/rayTracing.cpp rayTracing/rayTracing.h model/Object.h model/Sphere.cpp model/Sphere.h model/object_list.h model/object_list.cpp model/camera.cpp model/camera.h)
target_link_libraries(FirstRayTracing ${SDL2_LIBRARIES})