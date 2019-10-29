cmake_minimum_required(VERSION 3.14.2)
project(DeskCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(DeskCalculator main.cpp catch.hpp Token_stream.h Parser.h Funciones.h Error_Handling.h Calcular.h)