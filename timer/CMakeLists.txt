project(timer)

include(${CMAKE_SOURCE_DIR}/cmake/source.cmake)

target_link_libraries(${PROJECT_NAME} pthread)