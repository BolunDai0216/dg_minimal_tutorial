cmake_minimum_required(VERSION 3.15)

project(dg_minimal_tutorial)
set(CMAKE_CXX_STANDARD 17)

# depend on ament macros
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

# ROS2 dependencies
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(mim_msgs REQUIRED)
find_package(rclcpp REQUIRED)

# MiM dependencies.
find_package(mpi_cmake_modules REQUIRED)
find_package(dynamic_graph_manager REQUIRED)

# Dynamic graph dependencies.
find_package(dynamic-graph REQUIRED)
find_package(dynamic-graph-python REQUIRED)

# export de dependencies
ament_export_dependencies(
  ament_cmake
  ament_cmake_python
  std_msgs
  geometry_msgs
  mim_msgs
  rclcpp
  mpi_cmake_modules
  dynamic_graph_manager
  dynamic-graph
  dynamic-graph-python
)

# prepare to export all needed targets
ament_export_interfaces(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)

# Install launch files
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

# Library compilation
add_library(${PROJECT_NAME} src/dg_minimal_tutorial.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} dynamic_graph_manager::dynamic_graph_manager)
target_link_libraries(${PROJECT_NAME} dynamic-graph::dynamic-graph)
target_link_libraries(${PROJECT_NAME} dynamic-graph-python::dynamic-graph-python)

# Install config file
set(CONFIG_DESTINATION "share/${PROJECT_NAME}/dynamic_graph_manager")
install(FILES ${PROJECT_SOURCE_DIR}/config/dg_minimal_tutorial.yaml DESTINATION ${CONFIG_DESTINATION})

# Executables
add_executable(dg_minimal_tutorial_main src/dg_minimal_tutorial_main.cpp)
target_include_directories(dg_minimal_tutorial_main PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(dg_minimal_tutorial_main ${PROJECT_NAME})
target_compile_definitions(dg_minimal_tutorial_main PUBLIC CONFIG_PATH="${CMAKE_INSTALL_PREFIX}/${config_destination}/dg_minimal_tutorial.yaml")

# Install the include directory
install(DIRECTORY include/ DESTINATION include)

# Install the libraries
install(
  TARGETS ${PROJECT_NAME} dg_minimal_tutorial_main
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
  INCLUDES
  DESTINATION include
)

# Export as an ament_package
ament_package()