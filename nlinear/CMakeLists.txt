# ./nlinear/CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

add_library( nlinear )

include( GenerateExportHeader )
generate_export_header( nlinear EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/nlinear_export.h )
target_include_directories( nlinear PUBLIC ${CMAKE_BINARY_DIR}/exports )
target_include_directories( nlinear PRIVATE headers )

target_sources( nlinear
    PUBLIC  headers/vector.hxx
            headers/matrix.hxx
            headers/point.hxx
            headers/plane.hxx
    PRIVATE src/vector.cxx
            src/matrix.cxx
)