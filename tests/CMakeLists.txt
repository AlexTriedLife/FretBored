add_executable(FretBoredTests
        Scale_test.cpp

)
target_include_directories(FretBoredTests PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(FretBoredTests
        PRIVATE
        FretBoredLib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(FretBoredTests)
