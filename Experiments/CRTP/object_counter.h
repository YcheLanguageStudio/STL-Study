//
// Created by cheyulin on 7/21/16.
//

#ifndef STLSTUDY_OBJECT_COUNTER_H
#define STLSTUDY_OBJECT_COUNTER_H

#include <iostream>

template <typename T>
struct counter
{
    static int objects_created;
    static int objects_alive;

    static int print_alive_object_count();

    counter()
    {
        ++objects_created;
        ++objects_alive;
    }

    counter(const counter&)
    {
        ++objects_created;
        ++objects_alive;
    }
protected:
    ~counter() // objects should never be removed through pointers of this type
    {
        --objects_alive;
    }
};


template <typename T> int counter<T>::objects_created(0);
template <typename T> int counter<T>::objects_alive(0);

#endif //STLSTUDY_OBJECT_COUNTER_H
