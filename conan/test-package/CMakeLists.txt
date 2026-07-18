cmake_minimum_required(VERSION 3.24)

project(CommonUtilsTestConan LANGUAGES CXX)

find_package(CommonUtils REQUIRED COMPONENTS StringUtils MathUtils)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    TestPackage.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE o_lukas::StringUtils o_lukas::MathUtils)
