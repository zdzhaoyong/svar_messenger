cmake_minimum_required(VERSION 2.8)
project(svar_messenger)

include(cmake/PICMake.cmake)
set(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(src)

pi_add_target(svar_messenger SHARED src REQUIRED System LTO)
pi_add_target(without_header BIN example/without_header.cpp REQUIRED System)
pi_add_target(with_header BIN example/with_header.cpp REQUIRED System)

pi_report_target()

# Now do make install
pi_install(TARGETS svar_messenger)
