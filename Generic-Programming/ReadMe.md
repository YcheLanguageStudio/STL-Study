###泛型编程
- 这是新世纪以来C++的主流编程范式，带来了更快更好的代码，需要由编译器实例化
模板去解决T，U的类型推导，这些导致了模板元编程的诞生
- Boost库中四个泛型编程的工具：
    - enable_if 使用SFIANE原则，可以在编译期启用或禁用特定的泛型代码
    - call_traits  它是一个非标准元函数，计算类型T可能的多种类型，经常
    用于函数的入口参数或者返回参数的计算
    - concept_check 它以库的方式提供了泛型编程中急需的概念检查功能，
    在C++提供语言级别的概念检查之前是我们唯一可用的工具
    - function_types 它是一个类似type_traits的特征萃取库，但专门
    针对函数类型

###enable_if
- 主要用来解决模板函数或者模板类的重载解析问题，允许模板函数或者
模板类仅对某些类型有效，也就是说一句条件启用或者禁用某些特化形式。
- enbale_if/disable_if的工作原理设计到C++模板实例化的重载解析
- 如果某个参数或返回类型无效导致编译器推导失败无法实例化，
那么这个模板函数则不是候选函数，但是编译器也不认为这是一个错误。
SFIANE原则，替代失败不是错误。
- 类摘要：
```cpp
template<bool B, class T= void>  //T的缺省值是void
struct enable_if_c{
    typedef T type;             // 默认返回类型T
};

template<class T>
struct enable_if_c<flase, T>();   // 对False特化，无::type返回，有人在Cond::value==false时候实例化不会成功
```
- 作为模板推演时候的控制条件，enable_if通常需要跟type_traits或者Mpl使用来检查
类型T是否满足某些条件，可以放在模板参数列表的最后面用作缺省参数，或者是用作
返回值，两种形式想过是相同的，但有是偶止痛用一种形式，例如构造/析构函数没有返回值
- disable_if<>可以禁止函数的实例化

###call_traits
- 一个很小的泛型工具，封装了Ｃ++编写函数时候可能是“最好的”传参方式，会自动推导最高效的传递参数方式，避免出现引用的引用。
- 某个特化，例如call_traits这个中间层可以把Ｔ&的引用类型任然定义为Ｔ&，成功避免了引用的引用错误
- 对param_type计算的实现
```cpp
template <typename T, bool isp, bool b1>
struct ct_imp
{
  typedef const T& param_type;
};

//Specialization For Pointer Type
template <typename T, bool b1>
struct ct_imp<T, true, b1>
{
    typedef const T param_type;
};

//Specialization For Arithmetic Type
template <typename T, bool isp>
struct ct_imp<T, isp, true>{
  typedef typename ct_imp2<T, sizeof(T) <= sizeof(void*)::param_type param_type;
};

template <typename T, bool small_>
struct ct_imp2
{
  typedef const T& param_type;
};

template <typename T>
struct ct_imp2<T,true>{
  typedef const T param_type；
};
```
###总结
- enable_if 用于编写模板函数或者模板类
