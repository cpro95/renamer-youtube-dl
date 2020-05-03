cmake_minimum_required(VERSION 3.8)

set(This myTest)

set(Sources 
    myTest.cpp
)

set(Headers catch.hpp)

add_executable(${This} ${Sources} ${Headers})
target_link_libraries(${This}
    myStringLib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)