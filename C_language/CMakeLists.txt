cmake_minimum_required(VERSION 3.29)
project(C_language C)

set(CMAKE_C_STANDARD 11)
add_library(C_language STATIC library.c
        机组/机组.c
        应用密码学/欧几里得算法.c
        应用密码学/扩展欧几里得.c
        应用密码学/x-time计算.c
        "应用密码学/有限域GF(2^8)运算.c")
