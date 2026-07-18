project(MathUtilsTest)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/MathUtilTest.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE o_lukas::MathUtils GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME})
