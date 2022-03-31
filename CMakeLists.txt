# ./CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

# load meta information
include( "${CMAKE_CURRENT_SOURCE_DIR}/project_meta_info.in" )
project( nmath
    VERSION         ${project_version}
    DESCRIPTION     ${project_description}
    HOMEPAGE_URL    ${project_homepage}
    LANGUAGES       ${project_languages}
)

function( print_meta_info )
    message( "" )
    message( "project_version:      ${project_version}" )
    message( "project_description:  ${project_description}" )
    message( "project_homepage:     ${project_homepage}" )
    message( "project_languages:    ${project_languages}" )
    message( "" )
endfunction()
print_meta_info()

# set default binary symbol visibilities to hidden
if( NOT DEFINED CMAKE_CXX_VISIBILITY_PRESET AND
    NOT DEFINED CMAKE_VISIBILITY_INLINES_HIDDEN
)
    set( CMAKE_CXX_VISIBILITY_PRESET        hidden )
    set( CMAKE_VISIBILITY_INLINES_HIDDEN    YES )
endif()

# provided libraries
add_subdirectory( nlinear )