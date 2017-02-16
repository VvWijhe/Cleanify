cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "/media/victor/harde schijf/school/HBO2/semester_2/Female-Replacement/Tests/google_test/cmake-build-debug/googletest-src"
        BINARY_DIR        "/media/victor/harde schijf/school/HBO2/semester_2/Female-Replacement/Tests/google_test/cmake-build-debug/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )
