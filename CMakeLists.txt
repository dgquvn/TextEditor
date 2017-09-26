cmake_minimum_required(VERSION 2.6)

project(TextEditor)

# disable in-source builds
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# setup Doxygen
find_package(Doxygen)
if (DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Doxyfile.cmake ${CMAKE_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
endif(DOXYGEN_FOUND)

add_subdirectory(src)



