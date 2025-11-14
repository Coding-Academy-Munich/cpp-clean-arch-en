cmake_minimum_required(VERSION 3.20)

project(cpp_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(widgets_v1 WidgetV1.cpp WidgetV1.h WidgetV1Main.cpp)
add_executable(widgets_v2 WidgetV2.cpp WidgetV2.h WidgetV2Main.cpp)
add_executable(widgets_v3 WidgetV3.cpp WidgetV3.h propagate_const.h WidgetV3Main.cpp)
