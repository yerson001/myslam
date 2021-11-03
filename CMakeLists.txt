cmake_minimum_required(VERSION 3.5)
project(myslam)
set(CMAKE_CXX_FLAGS "-std=c++11")
#---------------to-opencv------------
#find_package( OpenCV REQUIRED ) #find_package( OpenCV 4 REQUIRED )
#include_directories( ${OpenCV_INCLUDE_DIRS})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# OpenCV
find_package(OpenCV REQUIRED)
file(GLOB_RECURSE VTK_LIBRARIES "/usr/local/lib/libopencv_viz.so") # todo ++
include_directories(${OpenCV_INCLUDE_DIRS})
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBS: ${OpenCV_LIBS}")
include_directories(include)
aux_source_directory(src DIR_SRCS)


MACRO(add_example name)
  ADD_EXECUTABLE(${name} src/${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${PROYECT_NAME} ${OpenCV_LIBS} ${VTK_LIBRARIES})
ENDMACRO()

add_example(main)
#add_example(programa2)
#add_example(programa3)
#add_example(programa4)