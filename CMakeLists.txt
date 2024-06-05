cmake_minimum_required(VERSION 3.11)
project(MatrixMultiplication)


find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})


# Utilizzo di FetchContent per includere Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0  
)
FetchContent_MakeAvailable(googletest)
# Aggiungi la directory degli header files
include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES src/main.cpp)

add_executable(main ${SOURCES})
target_link_libraries(main ${MPI_LIBRARIES} ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_without_errors.a)


add_executable(test_multiplication test/test_matrix_multiplication.cpp)
target_link_libraries(test_multiplication gtest gtest_main ${CMAKE_SOURCE_DIR}/lib/libmatrix_multiplication_without_errors.a ${MPI_LIBRARIES})


if (MPI_COMPILE_FLAGS)
  set_target_properties(main PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
  set_target_properties(test_multiplication PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif ()

if (MPI_LINK_FLAGS)
  set_target_properties(main PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
  set_target_properties(test_multiplication PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif ()

enable_testing()

include(GoogleTest)
gtest_discover_tests(test_multiplication)
