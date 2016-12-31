#STL-Study
##Build
如果需要测试的话，请用cmake加make工具自行build。我的环境是fedora23, gcc5.x, cmake 3.5,
 boost请用包管理器安装`boost`和`boost-dev*`。  

##Attention
详细内容可以看各个目录下的`ReadMe.md`。

##Content
- STL源码剖析
 
content | detail
--- | ---
[STLPuzzlingConfig](STLPuzzlingConfig) |  一些Compiler支持的特性，可见stl_config.h
[OtherPuzzlingPoints](OtherPuzzlingPoints) |  一些高级的用法，STL源码剖析中的
[Allocator](Allocator) | 内存配置器的实现，STL实现中最重要部分之一
    
- Boost程序库探秘

content | detail
--- | ---
[Meta-Programming](Meta-Programming) |  模板元编程一些基础知识
[Generic-Programming](Generic-Programming) |  泛性编程一些基础知识
[mpl库](MetaProgrammingLib) | boost模板元编程库的学习使用

- 其他实验

content | detail
--- | ---
[CRTP](Experiments/CRTP) | Curiously Recurring Template Pattern

##Related Books

book name | info
--- | ---
STL源码剖析 | 侯捷著
Boost程序库探秘 | 罗剑锋著
Boost程序库完全开发指南-深入C++准标准库 | 罗剑锋著
