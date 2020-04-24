cmake_minimum_required(VERSION 2.8)
project(svar_messenger)

include(PICMake)
set(CMAKE_CXX_STANDARD 11)

pi_add_target(svar_messenger SHARED src REQUIRED System LTO)
pi_add_target(svar_messenger_example BIN example REQUIRED System)

pi_report_target()

# Now do make install
get_property(TARGETS2COMPILE GLOBAL PROPERTY TARGETS2COMPILE)
pi_install(TARGETS ${TARGETS2COMPILE})
