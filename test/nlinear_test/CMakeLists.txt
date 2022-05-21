# ./atp/nlinear_test/CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

enable_testing()

add_executable( nlinear_test )
target_sources( nlinear_test
    PRIVATE vector_test.cxx
)

target_link_libraries( nlinear_test PUBLIC nlinear gtest_main )

include( GoogleTest )
gtest_discover_tests( nlinear_test )