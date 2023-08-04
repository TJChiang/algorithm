# https://zhuanlan.zhihu.com/p/598229845
cmake_minimum_required(VERSION 3.5)
project(leetcode-exercise)

set(CMAKE_CXX_STANDARD  17)

file(GLOB_RECURSE CPP_RESOURCE
        [0-9][0-9][0-9][0-9]-*/*.cpp
        )

file(GLOB_RECURSE structures_files CONFIGURE_DEPENDS
        structures/*.cpp
        structures/*.h
        )

foreach (FILE_PATH ${CPP_RESOURCE})
        STRING(REGEX REPLACE ".+./(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
        add_executable(${FILE_NAME} ${FILE_PATH}
                ${structures_files}
                )
endforeach ()
