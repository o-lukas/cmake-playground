project(ExecutablePlayground)

find_package(CLI11 REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE LibraryPlayground CLI11::CLI11)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT exe
)

install(FILES "${CMAKE_SOURCE_DIR}/LICENSE"
    DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT exe
)
