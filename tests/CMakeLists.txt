include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Исправлено: добавлен пробел между именем исполняемого файла и исходным файлом
add_executable(matrix_tests test_matrix.cpp)

# Исправлено: добавлен пробел после PRIVATE
target_link_libraries(matrix_tests PRIVATE gtest_main matrix_lib)

target_include_directories(matrix_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Исправлено: добавлен пробел после NAME
add_test(NAME matrix_tests COMMAND matrix_tests)
