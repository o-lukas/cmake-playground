cmake_minimum_required(VERSION 3.10)

project(CMakePlayground)

include(CTest)
include(GNUInstallDirs)

set(CMAKE_CXX_CLANG_TIDY clang-tidy;-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

set(CPACK_PACKAGE_NAME "CMakePlayground")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_CONTACT "meteor.kiwi-0i@icloud.com")
set(CPACK_GENERATOR "TGZ;ZIP")

include(CPack)
