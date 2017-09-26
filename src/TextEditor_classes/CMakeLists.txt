# set files
file(GLOB HEADERS *.hpp)
file(GLOB SRC *.cpp)

# set library type
SET(LIB_TYPE STATIC)

# set library
add_library(TextEditor_classes ${LIB_TYPE} ${SRC})

# no test files
