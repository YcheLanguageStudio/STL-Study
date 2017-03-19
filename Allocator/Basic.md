## Basic Concepts
### 各种type
- value_type
- pointer
- const pointer
- reference
- const reference
- size_type
- difference_type
- rebind(一个嵌套的class template)
- allocator()
- allocator(const allocator&)
- 泛化的copy constructor
- ~allocator
- address(reference x) const
- address(const_reference x) const
- allocate(size_type n, const void *=0) 第二个参数实现上可能会用来增强locality
- deallocate(pointer p, size_type n)
- max_size() const
- construct(pointer p, const T&x) 相当于new ((void *)p)T(x)
- destroy(pointer p) 相当于p->T()

### Corresponding Simple Implementation
- [YcheAllocator.h](./YcheAllocator.h)
- [YcheAllocator.cpp](./YcheAllocator.cpp)
