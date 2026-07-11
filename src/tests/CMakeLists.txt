project(TestsPlayground)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/StringUtilTest.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE LibraryPlayground)

add_test(NAME StringUtilTest COMMAND ${PROJECT_NAME})
