##Allocator概览
###[基本类型概念概览和无配置的实现](Basic.md)
###具备配置力的SGI Allocator
- SGI STL配置器与众不同，也与标准规范不同，其名称是alloc而非allocator，而且不接受任何参数。换句话说，
如果你想要在程序中采用SGI配置器，则不能使用标准写法。    
```cpp
vector<int, std::allocator<int> iv;// in VC or CB
```    
而只能写成下面这样：    
```cpp
vector<int, std::alloc> iv; // in GCC
```
- std::allocator只是对::operator new和 ::operator delete 做一层薄薄的包装而已,
详情请见[default allocator实现](defalloc.h)

###SGI特殊的空间配置器
- 一般而言，我们习惯的C++内存配置操作和释放操作是这样的：    
```cpp
  class Foo {...};
  Foo* pf = new Foo; //配置内存，然后构造对象
  delete pf;  //将对象析构，然后释放内存
```    
这其中的new算式包含两个阶段的操作：1）调用::operator new 配置内存， 2）调用Foo::Foo()构造对象内容。    
delete也包含两个阶段的操作：1）调用Foo::~Foo()把对象析构，2）调用::operator delete释放内存。     
为了精密的分工，STL allocator将这两阶段操作分开，内存配置操作由alloc::allocate负责，内存释放
由alloc::deallocate()负责；对象构造由：：construct()负责，对象析构操作由::destroy()负责    
- STL 标准规定，配置器定义于<memory>中，主要包含下面两个文件：   
```cpp
#include <stl_alloc.h>           //负责内存空间的配置与释放  定义了一级和二级配置器。配置器名为alloc
#include <stl_construct.h>       //负责对象内容的构造与析构  construct()   destroy()

#include <stl_unitialized.h>     //这里定义了一些全局函数，用来填充（fill）或者 复制(copy)大块内存数据
//e.g. un_initialized_copy() un_initialized_fill() un_initialized_fill_n()
//这些函数虽然不属于配置器的范畴，但是与对象初始值的设置有关。对于效率有面面俱到的考虑。最差情况下会用constrcut()，
最佳情况下会使用C标准函数memmove()直接进行内存数据的移动
 ```

###构造和析构的基本工具：constrcut() 和 destroy()

###空间的配置与释放，std::alloc
####第一级配置器 __malloc_alloc_template   

####第二级配置器 __default_alloc_template

####空间配置相关  allocate()  deallocate()  填充free lists

####内存池

###内存处理基本工具
- un_initialized_copy
- un_initialized_fill
- un_initialized_fill_n
