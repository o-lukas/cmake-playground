project(TestsPlayground)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/StringUtilTest.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE LibraryPlayground GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME})
