cmake_minimum_required(VERSION 3.24)

include(cmake/GenerateVersion.cmake)

project(CommonUtils
    VERSION ${VERSION_FULL}
    DESCRIPTION "A small CMake playground application"
    HOMEPAGE_URL "https://github.com/o-lukas/cmake-playground"
    LANGUAGES CXX)

option(ENABLE_CLANG_TIDY "Enables clang-tidy as static code analysis" OFF)
option(ENABLE_DOXYGEN "Enables doxygen for generating documentation" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CMakePackageConfigHelpers)
include(CTest)
include(GNUInstallDirs)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${VERSION_FULL}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    COMPONENT Development
)

if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXECUTABLE clang-tidy)
    if(CLANG_TIDY_EXECUTABLE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXECUTABLE};-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy")
    else()
        message(WARNING "Clang-Tidy executable not found. Static analysis will be disabled.")
    endif()
endif()

if(ENABLE_DOXYGEN)
    find_package(Doxygen)
    if(Doxygen_FOUND)
        set(DOXYGEN_GENERATE_HTML YES)
        set(DOXYGEN_GENERATE_LATEX NO)
        set(DOXYGEN_EXTRACT_ALL YES)
        set(DOXYGEN_QUIET YES)
        set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)

        file(GLOB_RECURSE _doxygen_source_files src/*)
        doxygen_add_docs(${PROJECT_NAME}_docs
            ${_doxygen_source_files} USE_STAMP_FILE
            COMMENT "Generate API documentation with Doxygen"
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        )

        install(
            DIRECTORY ${CMAKE_BINARY_DIR}/docs/html
            DESTINATION ${CMAKE_INSTALL_DOCDIR}
            COMPONENT Development)
    else()
        message(WARNING "Doxygen not found. Documentation generation will be disabled.")
    endif()
endif()

add_subdirectory(src)

if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.3.0")
    set(CMAKE_EXPERIMENTAL_GENERATE_SBOM
        2d856d6d-53e8-488b-a17f-d486d2cac317
    )
    install(
        SBOM ${PROJECT_NAME}
        EXPORTS CommonUtilsCliTargets MathUtilsTargets StringUtilsTargets
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/sbom
        LICENSE MIT
        COMPONENT Development
    )
else()
    message(STATUS "CMake SBOM support unavailable; skipping SBOM export")
endif()

set(CPACK_PACKAGE_NAME "CommonUtils")
set(CPACK_PACKAGE_DESCRIPTION "A small CMake playground application")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "meteor.kiwi-0i@icloud.com")
set(CPACK_PACKAGE_VENDOR "Lukas Obermeier")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A small CMake playground application")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CPACK_PACKAGE_NAME}")
set(CPACK_COMPONENTS_GROUPING ALL_COMPONENTS_IN_ONE)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_EXTERNAL_PACKAGE_SCRIPT ${CMAKE_SOURCE_DIR}/extern/cpack-conan/CPackConan.cmake)

set(CPACK_EXTERNAL_ENABLE_STAGING ON)

set(CPACK_CONAN_COMPONENT_INSTALL ON)
set(CPACK_CONAN_PACKAGE_GENERATORS CMakeConfigDeps)
set(CPACK_CONAN_PACKAGE_SETTINGS os compiler build_type arch)
set(CPACK_CONAN_PACKAGE_LICENSE MIT)
set(CPACK_CONAN_PACKAGE_ADDITIONAL_PYTHON_SCRIPT ${CMAKE_SOURCE_DIR}/conan/ConanFileAdditional.py)
set(CPACK_CONAN_PACKAGE_TEST_PACKAGE_FILES
    ${CMAKE_SOURCE_DIR}/conan/test-package/conanfile.py
    ${CMAKE_SOURCE_DIR}/conan/test-package/CMakeLists.txt
    ${CMAKE_SOURCE_DIR}/conan/test-package/TestPackage.cpp
)

if(WIN32)
    set(CPACK_GENERATOR NSIS;ZIP)
    set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_NAME}")
    set(CPACK_NSIS_CONTACT "${CPACK_PACKAGE_CONTACT}")
elseif(APPLE)
    set(CPACK_GENERATOR External;DragNDrop;ZIP)
    set(CPACK_BUNDLE_NAME "${CPACK_PACKAGE_NAME}")
    set(CPACK_DMG_VOLUME_NAME "${CPACK_PACKAGE_NAME}")
    set(CPACK_DMG_FORMAT "UDZO")
    set(CPACK_DMG_DROP_LINK "Applications")
elseif(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR External;DEB;TGZ)
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${CPACK_PACKAGE_CONTACT}")
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    set(CPACK_DEBIAN_ARCHITECTURE "${CMAKE_SYSTEM_PROCESSOR}")
endif()

include(CPack)
