# STL-Study
##描述
- 这个仓库将会把STL源码剖析，Boost程序库探秘中的代码搬运过来。    
- 如果需要测试的话，请用cmake加make工具自行build。  
- 我的环境是fedora23, gcc5.x, cmake 3.5, Boost请用包管理器安装boost和boost-dev*。  

##内容
- STL源码剖析
    - [STLPuzzlingConfig 一些Compiler支持的特性，可见stl_config.h](STLPuzzlingConfig)
    - [OtherPuzzlingPoints 一些高级的用法，STL源码剖析中的](OtherPuzzlingPoints)
    - [Allocator 内存配置器的实现，STL实现中最重要部分之一](Allocator)
- Boost程序库探秘
    - [Meta-Programming 模板元编程一些基础知识](Meta-Programming)
    - [Generic-Programming 泛性编程一些基础只是](Generic-Programming)

##引用
- STL源码剖析-侯捷著
- Boost程序库探秘