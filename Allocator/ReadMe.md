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
