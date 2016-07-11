###模板元编程
- 元程序是在编译期间执行的程序，操作的对象也不是普通的变量
- 因此不能使用c++运行时的关键字（if, else , for） 可用的语法非常有限
- 最常用的语法
  - enum/static， 用来定义编译期间的整数常量
  - typedef/using, 最重要的元编程关键字，用来定义元数据
  - template, 元编程的“起点”， 主要用于定义元函数
  - “::”， 域作用符， 用于解析类型作用域获取计算结果（元数据）
- 更高级的用法
  - lambda表达式/容器/迭代器/算法/视图等更高级的概念
- TypeTraits
    - type_traits提供了一组traits类，也就是元函数，可以在编译时候确定类型（元数据通过using或typedef来使用）是否具有某些traits，
    或者为某些类型添加或移除const/volatile等修饰词，提供上百个元函数（就是模板类),主要有以下两大类
        - 检查元数据属性的值的元函数： 以::value返回一个bool值或一个证书
        - 操作元数据的标准元函数： 以::type返回一个新的元数据（类型）
    - 以is或has开头的元函数都属于值元函数，其他属于标准元函数，一些有例外
    
###例子
- [Basic Intro of Meta-Programming](MetaFunction.cpp)
- [Meta-Function Forward](MetaFunctionForward.cpp)
- [Util header](MetaFunctionTool.h)
- [Small Demo Case MetaFunction Util](MetaFunctionTool.cpp)
- [Type Traits Value Usage](TypeTraitsUsage.cpp)