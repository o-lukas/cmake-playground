if(NOT DEFINED GIT_EXECUTABLE)
    find_program(GIT_EXECUTABLE git)
endif()

if(NOT GIT_EXECUTABLE)
    message(FATAL_ERROR "Git executable not found")
endif()

execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=0
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE git_result
    OUTPUT_VARIABLE git_tag
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(NOT git_result EQUAL 0)
    message(WARNING "Failed to find the latest Git tag")
    set(git_tag "v0.0.1")
endif()

string(REGEX MATCH "^v?([0-9]+)\.([0-9]+)\.([0-9]+)$" _semver_match ${git_tag})
if(NOT _semver_match)
    message(FATAL_ERROR "Git tag '${git_tag}' is not a valid SemVer tag")
endif()

set(VERSION_MAJOR ${CMAKE_MATCH_1})
set(VERSION_MINOR ${CMAKE_MATCH_2})
set(VERSION_PATCH ${CMAKE_MATCH_3})
set(VERSION_FULL ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

message(STATUS "VERSION_MAJOR: ${VERSION_MAJOR}")
message(STATUS "VERSION_MINOR: ${VERSION_MINOR}")
message(STATUS "VERSION_PATCH: ${VERSION_PATCH}")
message(STATUS "VERSION_FULL: ${VERSION_FULL}")
