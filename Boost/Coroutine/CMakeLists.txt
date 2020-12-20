project(Coroutine)
find_package(Boost COMPONENTS context)
include(${CMAKE_SOURCE_DIR}/cmake/source.cmake)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})