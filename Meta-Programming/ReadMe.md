### 模板元编程简介

- 元程序是在编译期间执行的程序，操作的对象也不是普通的变量。因此不能使用c++运行时的关键字（if, else , for） 可用的语法非常有限

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

- type_traits 库提供四个元函数计算元数据之间的关系，它们都是两参数元函数，使用::value返回bool类型的检查参数

- Meta-Data Computations(1)
    - add_const<T> 返回T const
    - add_lvalue_reference<T> 对于对象或者函数类型返回左值引用，通常是T&，否则是T
    - add_rvalue_reference<T> 对于对象或者函数类型返回右值引用，通常是T&&, 否则是T
    - remove_cv<T> 移除T的顶层const和volatile修饰

- Meta-Data Computations(2)
    - make_signed<T>
    - make_unsigned<T>
    - integral_promotion<T>
    - promote<T>
    - remove_extent<T> 移除数组的最顶层维度
    - remove_bounds<T> 同上，但非C++11标准
    - remove_all_extents<T> 变为普通类型    

- Meta-Data Computations(3)
    - conditional<b, T, U> 条件运算，类似于mpl::if_c<> 根据b的真假决定返回T或U
    - common_type<T, ...> : 求多个类型的共通类型（类似于数字的最小共倍数）对类型的顺序由要求
    - decay<T> : 先执行remove_reference<T>得到元数据U, 如果U为数组类型， 返回remove_extent<T>*，
    若为函数类型，则结果为U*, 否则返回U。通常来说，decay<T>得到一个值类型

- Function Meta Data
    - 解析元数据的元函数function_traits<>不属于C++11标准，是一个非标准元函数，能返回多个值，
    包括函数的参数数量/参数类型/返回类型，支持解析最多10个参数的函数
    - function_traits<T>要求输入的元数据(tpye)，必须要满足is_function<T>::value==true，不能是
    函数指针或者引用。如果是函数指针或引用，那么可以用remove_pointer<T>，remove_reference<T>来转换
    类型，否则会导致编译错误，:blush:
    - 摘要如下：   
    ```cpp
    template <class T>
    sturct function_traits
    {
        static const std::size_t arity;  //arity意思是参数数量
        typedef some-define result_type; //函数的返回类型
        typedef some-define argN_type;   //返回函数第N个参数的类型
    }
    ```
    - boost::result_of<>::type可以处理任意可调用类型，函数/函数指针和函数对象

### TypeTraits使用的例子

- [Basic Intro of Meta-Programming](MetaFunction.cpp)
- [Meta-Function Forward](MetaFunctionForward.cpp)
- [Util header](MetaFunctionTool.h)
- [Small Demo Case MetaFunction Util](MetaFunctionTool.cpp)
- [Type Traits Value Usage](TypeTraitsUsage.cpp)
- [Meta Computation](MetaDataComputation.cpp)
- [Meta Computation 2](MetaDataComputationOthers.cpp)
- [Meta Relation](MetaDataRelation.cpp)
- [Function Meta Data](ParseFunctionMetaData.cpp)    

### Boost的type_traits实现原理
   - 实现比较复杂，而且使用了***预处理元编程***和一些特别的技巧
   - 下面针对is_integral<>为例子简单阐述实现原理
    - type_traits库里面许多值元函数都使用了元函数转发技术，把元参数转发给元函数integral_constant<>进行计算
        （这个又把元参数转发给了元函数mpl::integral_c<>）进行计算，也就是说integral_constant>是大多数值元函数
        的public基类。
    - 类摘要：

    ```cpp
    template <class T, T val>    //计算类型为T，值为val的整数
    struct integral_constant
    {
        typedef integral_constant<T, val> type;  //定义自身为返回元数据
        typedef T value_type;     //返回值的类型
        static const T value = val;       //以::value 返回整数值 val
        // BOOST_STATIC_CONSTANT(T, value=val)  //Could be Replaced With this Macro
    }
    ```   

   - 因为type_traits中大部分元函数的计算结果是Bool值，因此type_traits库又特别提供了两个针对Bool元数据
    特化的无参元函数true_type和false_type   

   ```cpp
   typedef integral_constant<bool, true> true_type;
   typedef integral_constant<bool, false> false_type;
   ```   

   - is_integral<> 使用了模板特化技术，对于非整数的类型元函数   

   ```cpp
   template<typename T>
   struct is_integral: boost::integral_constant<bool, false> //元函数转发，返回false
   {};

   template<>
   struct is_integral<bool>: boost::integral_constant<bool,true>  //元函数转发，返回true

   template<>
   struct is_integral<char> : booost::integral_constant<bool, true>
   ```

### 例子

- [Integral Constant](IntegralConstantStudy.cpp)

### 模板元编程应用例子

- [Conditional](Apps/Conditional.cpp) 实现[MetaFuctionTool](MetaFunctionTool.cpp)中功能
    - 总结：使用type_traits元函数实现明显比直接的模板特化复杂，充分展现了模板元编程的函数式本质，
程序的实现都是通过函数的嵌套调用完成的，程序员需要在头脑中维护一个“函数的堆栈”才能搞清楚它们的调用过程。
    - 实际上conditional<>并没有左什么更多的工作，它知识对mpl::if_c的元函数转发  
    ```cpp
    template<bool b, class T, class U>
    struct conditional: public mpl::if_c<b, T, U>  //元函数转发
    {};
    ```
    - boost.mpl里另有一个元函数eval_if<>也可以达到相同效果

- [Identity Type](Apps/IdentityType.cpp)
    - 问题：C/C++预处理器会把逗号识别成宏参数分隔符，不能理解C++模板语法的尖括号，所以在宏里使用带有逗号的
    模板类会导致参数解析错误  

- [declval](Apps/Declval.cpp)
    - C++11标准中一个特别的函数模板
    ```cpp
    template <typename T>
    typename add_rvalue_reference<T>::type declval();
    ```
    - Boost中在boost/utility/decval.hpp中实现了它
    - type_traits里面的common_type<>使用了decval()实现，计算两个类型的代码：
    ```cpp
    template<typename T, typename U>
    struct common_type<T, U>{
        typedef decltype(decval<bool> ? decval<T>() : decval<U>()) type;
    }
    ```
    - 对于更多拉稀行的共通计算,common_type<>使用了递归
    ```cpp
    template<typename T, typename U, typename... V>   //C++11可变参数列表
    struct common_type<T, U, V...>
    public:
        typedef typename common_type<       //递归调用common_type
            typename common_type<T,U>::type, V...>::type type;
    ```

### 总结
- 模板元编程基本概念：元数据(类型)，元函数（模板类），元函数转发（通过继承，改变参数位置等应用）。
- 主要用途：类型推导
- 元数据：可以是整数（含bool）或任意c++类型
- 元函数：元编程的核心，内部定义::type或者::value返回计算的结果
- 元函数转发：通过使用public继承元函数的方式实现
- 其他既有的库
    - std::result_of 能够推导出调用类型（函数，函数指针，函数对象）的返回值
    - std::unwrap_reference<T> 揭开boost::reference_wrapper的包装
    - boost::call_traits：推导出最适合的调用参数类型
- Traits是一个重要概念，萃取类型中重要的信息，如iterator_traits和function_traits    
