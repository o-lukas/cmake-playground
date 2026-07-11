cmake_minimum_required(VERSION 3.10)

include(cmake/GenerateVersion.cmake)

project(CMakePlayground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
include(GNUInstallDirs)

find_program(CLANG_TIDY_EXECUTABLE clang-tidy)
if(CLANG_TIDY_EXECUTABLE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXECUTABLE};-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy")
else()
    message(WARNING "Clang-Tidy executable not found. Static analysis will be disabled.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

set(CPACK_PACKAGE_NAME "CMakePlayground")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "meteor.kiwi-0i@icloud.com")
set(CPACK_GENERATOR "TGZ;ZIP")

include(CPack)
