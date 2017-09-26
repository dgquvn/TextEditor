# set the library directory
set(TextEditor_class_dir
  ${CMAKE_CURRENT_SOURCE_DIR}/TextEditor_classes)

# include the library
include_directories(${TextEditor_class_dir})

add_subdirectory(TextEditor_classes)

# setup boost package
find_package(Boost REQUIRED COMPONENTS program_options)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(text_editor text_main.cpp)
  target_link_libraries(text_editor ${Boost_PROGRAM_OPTIONS_LIBRARIES} TextEditor_classes)
endif()
