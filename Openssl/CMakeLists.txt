project(Openssl)

include(${CMAKE_SOURCE_DIR}/cmake/child.cmake)
set(OPENSSL_ROOT_DIR $ENV{HOME}/3rd_party)
find_package(OpenSSL)

AddSub()