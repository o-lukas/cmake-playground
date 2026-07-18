project(CommonUtilsCli)

find_package(CLI11 REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE StringUtils CLI11::CLI11)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT Runtime
)

install(FILES "${CMAKE_SOURCE_DIR}/LICENSE"
    DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT Runtime
)
