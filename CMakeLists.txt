cmake_minimum_required(VERSION 4.0)
project(leetcode-exercise)

set(CMAKE_CXX_STANDARD  17)
include_directories(${PROJECT_SOURCE_DIR}/structures/cpp)

file(GLOB_RECURSE CPP_RESOURCE
        leetcode/[0-9][0-9][0-9][0-9]-*/*.cpp
        others/**/*.cpp
        )

file(GLOB_RECURSE structures_files CONFIGURE_DEPENDS
        structures/cpp/**/*.cpp
        structures/cpp/**/*.h
        )

foreach (FILE_PATH ${CPP_RESOURCE})
        # 從路徑中取得不含副檔名的檔案名稱
        get_filename_component(FILE_NAME ${FILE_PATH} NAME_WE)

        add_executable(${FILE_NAME} ${FILE_PATH}
                ${structures_files}
                )
endforeach ()
# https://zhuanlan.zhihu.com/p/598229845
