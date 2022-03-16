# CMakeLists.txt

cmake_minimum_required( VERSION 3.21 )

include( "${CMAKE_CURRENT_LIST_DIR}/common_project_include.in" )

message( "" )
message( "project_version = ${project_version}" )
message( "project_description = ${project_description}" )
message( "project_homepage = ${project_homepage}" )
message( "" )

project( nmath
    VERSION ${project_version}
    DESCRIPTION ${project_description}
    HOMEPAGE_URL ${project_homepage}
    LANGUAGES CXX
)

add_library( nmath SHARED )

target_sources( nmath
    PRIVATE src/vector.cxx
            src/matrix.cxx
    PUBLIC  headers/vector.hxx
            headers/matrix.hxx
)