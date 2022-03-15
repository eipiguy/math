# CMakeLists.txt

cmake_minimum_required( VERSION 3.21 )

set( CMAKE_PROJECT_INCLUDE_BEFORE
    "${CMAKE_CURRENT_LIST_DIR}/common_project_include.in"
)

project( nmath
    VERSION ${project_version}
    PROJECT_DESCRIPTION ${project_description}
    LANGUAGES CXX
)

add_library( nmath
    PRIVATE src/vector.cxx
            src/matrix.cxx
    PUBLIC  include/vector.hxx
            include/matrix.hxx
)