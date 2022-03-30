# ./nlinear/CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

add_library( nlinear )
target_sources( nlinear
    PUBLIC  headers/vector.hxx
            headers/matrix.hxx
            headers/point.hxx
            headers/plane.hxx
    PRIVATE src/vector.cxx
            src/matrix.cxx
)