###历史
The technique was formalized in the 1980s as "F-bounded quantification". 
The name "CRTP" was independently coined by Jim Coplien in 1995,
 who had observed it in some of the earliest C++ template code as well as 
 in code examples that Timothy Budd created in his multiparadigm language Leda.
 
###静态多态(Static polymorphism)
- Typically, the base class template will take advantage of the fact that member 
function bodies (definitions) are not instantiated until long after their declarations, 
and will use members of the derived class within its own member functions, 
via the use of a cast; e.g.:    
```cpp
template <class T> 
struct Base
{
    void interface()
    {
        // ...
        static_cast<T*>(this)->implementation();
        // ...
    }

    static void static_func()
    {
        // ...
        T::static_sub_func();
        // ...
    }
};

struct Derived : public Base<Derived>
{
    void implementation();
    static void static_sub_func();
};
```    
- In the above example, note in particular that the function Base<Derived>::interface(), 
though declared before the existence of the struct Derived is known by the compiler 
(i.e., before Derived is declared), is not actually instantiated by the compiler 
until it is actually called by some later code which occurs after 
the declaration of Derived (not shown in the above example), 
so that at the time the function "interface" is instantiated, 
the declaration of Derived::implementation() is known.   
- This technique achieves a similar effect to the use of virtual functions, 
without the costs (and some flexibility) of dynamic polymorphism. 
This particular use of the CRTP has been called "simulated dynamic binding" by some. 
This pattern is used extensively in the Windows ATL and WTL libraries.  

###例子
- CRTP Def
    - [Formal Definition Header](formal_base.h)
    - [Formal Definition Cpp](formal_algorithm.cpp)
- Object Counter Demo
    - [Object Counter Header](object_counter.h)
    - [Object Counter Cpp](instance_object_counter.cpp)
