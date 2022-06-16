cmake_minimum_required(VERSION 3.12)
project(test-autoparallel)
add_compile_options(/O2 /Qpar /Qpar /Qpar-report:2 /Qvec-report:2)
add_executable(main main.cpp)