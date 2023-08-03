# https://zhuanlan.zhihu.com/p/598229845
cmake_minimum_required(VERSION 3.5)
project(leetcode-exercise)

set(CMAKE_CXX_STANDARD  17)

file(GLOB CPP_RESOURCE
        [0-9][0-9][0-9][0-9]-*/*.cpp
        )
file(GLOB STRUCTURES_RESOURCE
        structures/*.cpp
        )
file(GLOB STRUCTURES_HEADERS_RESOURCE
        structures/*.h
        )

foreach (FILE_PATH ${CPP_RESOURCE})
        STRING(REGEX REPLACE ".+./(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
        add_executable(${FILE_NAME} ${FILE_PATH})
endforeach ()

foreach (FILE_PATH ${STRUCTURES_RESOURCE})
    STRING(REGEX REPLACE ".+./(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
    add_executable(${FILE_NAME} ${FILE_PATH}
            ${STRUCTURES_HEADERS_RESOURCE})
endforeach ()