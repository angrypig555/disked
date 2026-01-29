cmake_minimum_required(VERSION 3.10.0)
project(disked VERSION 0.1.0 LANGUAGES C CXX)

add_executable(disked src/backend-interface.cpp src/manage-disk.cpp src/disks.hpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
