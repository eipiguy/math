# ./nmathConfig.cmake
cmake_minimum_required( VERSION 3.15 )

# component variables
set( nmath_known_comps static shared )
set( nmath_comp_static NO )
set( nmath_comp_shared NO )

# check that "find_package" is looking for existing component
foreach( nmath_comp IN LISTS ${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS )
    if( nmath_comp IN_LIST nmath_known_comps )
        set( nmath_comp_${nmath_comp} YES )
    else()
        set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "nmath does not recognize component '${nmath_comp}'"
        )
        set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE )
        return()
    endif()
endforeach()

# if both components requested, returns error
if( nmath_comp_static AND nmath_comp_shared )
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
        "nmath 'static' and 'shared' componends are mutually exclusive"
    )
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE )
    return()
endif()

# load target scripts
set( nmath_static_targets
    "${CMAKE_CURRENT_LIST_DIR}/nmath-static-targets.cmake"
)
set( nmath_shared_targets
    "${CMAKE_CURRENT_LIST_DIR}/nmath-shared-targets.cmake"
)

# load targets macro
macro( nmath_load_targets type )
    if( NOT EXISTS "${nmath_${type}_targets" )
        set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "nmath '${type}' libraries were requested but not found"
        )
        set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE )
        return()
    endif()
    include( "${nmath_${type}_targets" )
endmacro()

# default static before shared unless requested or BUILD_SHARED_LIBS set
# if requested doesn't exist, revert to available
if( nmath_comp_static )
    nmath_load_targets( static )
elseif( nmath_comp_shared )
    nmath_load_targets( shared )
elseif( DEFINED nmath_SHARED_LIBS AND nmath_SHARED_LIBS )
    nmath_load_targets( shared )
elseif( DEFINED nmath_SHARED_LIBS AND NOT nmath_SHARED_LIBS )
    nmath_load_targets( static )
elseif( BUILD_SHARED_LIBS )
    if( EXISTS "${nmath_shared_targets}" )
        nmath_load_targets( shared )
    else()
        nmath_load_targets( static )
    endif()
else()
    if( EXISTS "${nmath_static_targets}" )
        nmath_load_targets( static )
    else()
        nmath_load_targets( shared )
    endif()
endif()