project(Boost_TcpClient)
include(${CMAKE_SOURCE_DIR}/cmake/source.cmake)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Boost/Log/logwrapper)
target_link_libraries(${PROJECT_NAME} PUBLIC pthread Boost_Log_logwrapper)
