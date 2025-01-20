cmake_minimum_required(VERSION 3.17)
project(rocfft_call LANGUAGES CXX HIP)
list(APPEND CMAKE_PREFIX_PATH $ENV{ROCM_PATH}/hip $ENV{ROCM_PATH} ~/rocfft-install)
find_package(HIP REQUIRED)
find_package(ROCFFT REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(rocfft_call example_rocfft.cpp)
add_executable(recursive_example fft.cpp)
add_executable(gen_random_complex random.cpp)
target_link_libraries(rocfft_call hip::device hip::host roc::rocfft)
