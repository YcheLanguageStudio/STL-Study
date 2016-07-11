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

###例子
- [Basic Intro of Meta-Programming](MetaFunction.cpp)
- [Meta-Function Forward](MetaFunctionForward.cpp)
- [Small Demo Case MetaFunction Util](MetaFunctionTool.cpp)
  [Util header](MetaFunctionTool.h)