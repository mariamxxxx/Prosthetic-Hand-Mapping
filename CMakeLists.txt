project_name: esp32-potentiometer-project
version: 0.1

cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(esp32-potentiometer-project)

set(COMPONENT_SRCS "main/potentiometer_main.c")
set(COMPONENT_ADD_INCLUDEDIRS "main")

register_component()