find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(armadilo_test test.cpp)
target_link_libraries(armadilo_test ${ARMADILLO_LIBRARIES}) 
