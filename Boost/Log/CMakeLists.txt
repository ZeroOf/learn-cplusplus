project(Log)

find_package(Boost COMPONENTS log log_setup)

set(CMAKE_BUILD_RPATH $ENV{HOME}/3rd_party/lib)
include(${CMAKE_SOURCE_DIR}/cmake/source.cmake)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

