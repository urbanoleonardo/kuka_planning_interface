cmake_minimum_required(VERSION 2.8.3)
project(test_kuka)

find_package(catkin REQUIRED std_tools tf roscpp mathlib robotlib cds_execution
tf cmake_modules kuka_action_server kuka_action_client)



set(CMAKE_CXX_FLAGS "-O2 -O3 -std=c++11 -mtune=native -fPIC -Wall")



## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
   CATKIN_DEPENDS std_tools tf
)


set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(include ${catkin_INCLUDE_DIRS} ${INCLUDE_DIR} ${catkin_INCLUDE_DIRS})



# --- Create Action Server Node Test actions

add_executable(test_server_node  ${INCLUDE_DIR}/test_kuka/test_action_server.h 
 				 ${SRC_DIR}/test_action_server.cpp
				 ${SRC_DIR}/test_action_server_node.cpp	)
target_link_libraries(test_server_node ${catkin_LIBRARIES})

# --- Create Action Client Node Test action

add_executable(test_client_node ${INCLUDE_DIR}/test_kuka/test_action_client.h
                                ${SRC_DIR}/test_action_client.cpp
                                ${SRC_DIR}/test_action_client_node.cpp)
target_link_libraries(test_client_node ${catkin_LIBRARIES})




