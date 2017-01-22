cmake_minimum_required(VERSION 3.0)
project(tinyxml2_example)
include(ExternalProject)
set (CMAKE_CXX_STANDARD 11)
set(EXTERNAL_INSTALL_LOCATION ${PROJECT_SOURCE_DIR})                             
#ExternalProject_Add(googletest                                                   
# GIT_REPOSITORY https://github.com/google/googletest                          
# GIT_TAG release-1.8.0                                                        
# CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}               
#)
ExternalProject_Add(tinyxml2                                                     
  GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git                   
  GIT_TAG 4.0.1                                                                
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}               
)
## Order problem?? include path, link directory and then executable
## and link library
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)
link_directories(
  ${PROJECT_SOURCE_DIR}/lib
)
add_executable(make_xml 
  src/make_xml.cc
)
#find_library(tinyxml2 
#  HINTS ${PROJECT_SOURCE_DIR}/lib
#) 
#find_package(tinyxml2 REQUIRED) 
#if (TINYXML2_FOUND)
#  message("tinyxml2 found")
#  include_directories(${TINYXML2_INCLUDE_DIRS})
#  target_link_libraries (make_xml ${TINYXML2_LIBRARIES})
#else(TINYXML2_FOUND)
#  message("tinyxml2 not found")
#endif (TINYXML2_FOUND)
## tinyxml2 is not working .... why
target_link_libraries(make_xml 
  libtinyxml2.dylib
)
add_dependencies(make_xml tinyxml2)
