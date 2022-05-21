# ./atp/CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

# load meta information
include( "${CMAKE_CURRENT_SOURCE_DIR}/project_meta_info.in" )
project( nmath_test
    VERSION         ${project_version}
    DESCRIPTION     ${project_description}
    HOMEPAGE_URL    ${project_homepage}
    LANGUAGES       ${project_languages}
)

message( "" )
message( "project_version:      ${project_version}" )
message( "project_description:  ${project_description}" )
message( "project_homepage:     ${project_homepage}" )
message( "project_languages:    ${project_languages}" )
message( "" )

# set default binary symbol visibilities to hidden
if( NOT DEFINED CMAKE_CXX_VISIBILITY_PRESET AND
    NOT DEFINED CMAKE_VISIBILITY_INLINES_HIDDEN
)
    set( CMAKE_CXX_VISIBILITY_PRESET        hidden )
    set( CMAKE_VISIBILITY_INLINES_HIDDEN    YES )
endif()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package( nlinear )

# provided libraries
add_subdirectory( nlinear_test )

# installation
include( GNUInstallDirs )
install(
    TARGETS nlinear_test
    EXPORT  nlinear_test_targets

    INCLUDES    DESTINATION         "${CMAKE_INSTALL_INCLUDEDIR}"

    RUNTIME     DESTINATION         "${CMAKE_INSTALL_BINDIR}"
                COMPONENT           nmath_test_runtime
    LIBRARY     DESTINATION         "${CMAKE_INSTALL_LIBDIR}"
                COMPONENT           nmath_test_runtime
                NAMELINK_COMPONENT  nmath_test_development
    ARCHIVE     DESTINATION         "${CMAKE_INSTALL_LIBDIR}"
                COMPONENT           nmath_test_development
)