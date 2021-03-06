cmake_minimum_required(VERSION 2.8.3)
project(kuka_action_server)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED std_tools roscpp mathlib robotlib cds_execution tf cmake_modules optitrack_rviz)

set(CMAKE_CXX_FLAGS "-O2 -O3 -std=c++11 -fext-numeric-literals -mtune=native -fPIC -Wall -Wno-deprecated-declarations")

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES ${PROJECT_NAME} optitrack_rviz
   CATKIN_DEPENDS std_tools tf mathlib optitrack_rviz
#  DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS})


set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


find_package(Eigen)
include_directories(${INCLUDE_DIR} ${catkin_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS})


set(H_FILES  	${INCLUDE_DIR}/kuka_action_server/base_action_server.h
                ${INCLUDE_DIR}/kuka_action_server/default_types.h
                ${INCLUDE_DIR}/kuka_action_server/base_ee_action.h
                ${INCLUDE_DIR}/kuka_action_server/base_j_action.h
                ${INCLUDE_DIR}/kuka_action_server/default_topics.h
                ${INCLUDE_DIR}/kuka_action_server/default_services.h
                ${INCLUDE_DIR}/kuka_action_server/action_server.h
                ${INCLUDE_DIR}/kuka_common_action_server/action_initialiser.h
                ${INCLUDE_DIR}/kuka_common_action_server/kuka_goto_cart_as.h
                ${INCLUDE_DIR}/kuka_common_action_server/kuka_goto_joint_as.h
                ${INCLUDE_DIR}/kuka_common_action_server/kuka_grav_as.h
                ${INCLUDE_DIR}/kuka_common_action_server/speed_generator.h
                ${INCLUDE_DIR}/kuka_common_action_server/si_units.h
)

set(SRC_FILES   ${SRC_DIR}/base_ee_action.cpp
                ${SRC_DIR}/base_j_action.cpp
                ${SRC_DIR}/action_server.cpp
                ${SRC_DIR}/default_topics.cpp
                ${SRC_DIR}/kuka_common_action_server/kuka_goto_cart_as.cpp
                ${SRC_DIR}/kuka_common_action_server/kuka_goto_joint_as.cpp
                ${SRC_DIR}/kuka_common_action_server/kuka_grav_as.cpp
                ${SRC_DIR}/kuka_common_action_server/speed_generator.cpp
)

add_library(${PROJECT_NAME} SHARED ${H_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}  ${catkin_LIBRARIES} )

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
