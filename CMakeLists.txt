cmake_minimum_required (VERSION 3.8)

project ("EmbedNet")

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Poco REQUIRED COMPONENTS Foundation Net)

add_subdirectory ("EmbedNet")