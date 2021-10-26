cmake_minimum_required(VERSION 3.20)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

# add_executable(data_structure main.c helloworld.c)
# 遍历项目根目录下所有的 .c 文件
file (GLOB_RECURSE files *.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} 111.c)
    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
