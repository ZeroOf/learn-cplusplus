cmake_minimum_required(VERSION 3.16)
project(cpp_practice VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

configure_file(config/version.h.in version.h)

set(BOOST_ROOT $ENV{HOME}/3rd_party)
include_directories(INTERFACE $ENV{HOME}/3rd_party/include)
link_directories($ENV{HOME}/3rd_party/lib)

add_subdirectory(DataStruct)
add_subdirectory(Dictionary)
add_subdirectory(config)
add_subdirectory(interface)
add_subdirectory(DesignPattern)
add_subdirectory(Boost)
add_subdirectory(timer)
add_subdirectory(Algorithm)
add_subdirectory(HttpServer)
add_subdirectory(WordsCounter)
add_subdirectory(WordsSearcher)
add_subdirectory(textquery)
add_subdirectory(Openssl)
add_subdirectory(eventfd)

# pacakge
include(InstallRequiredSystemLibraries)
include(CPack)