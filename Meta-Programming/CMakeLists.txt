find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(MetaFunction MetaFunction.cpp)
add_executable(MetaFunctionForward MetaFunctionForward.cpp)
add_executable(MetaFunctionUtilDemo MetaFunctionTool.cpp MetaFunctionTool.h)


