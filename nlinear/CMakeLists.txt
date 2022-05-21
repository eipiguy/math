# ./nlinear/CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

add_library( nlinear )

include( GenerateExportHeader )
generate_export_header( nlinear EXPORT_FILE_NAME
    "${CMAKE_CURRENT_SOURCE_DIR}/headers/nlinear_export.h"
)
target_include_directories( nlinear PUBLIC headers )

target_sources( nlinear
    PRIVATE src/vector.cxx
            src/matrix.cxx
)