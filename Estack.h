/*
*   author:Wildpointer
*   date:2022-3-28
*   about:Estack类
*/
#ifndef ESTACK_H
#define ESTACK_H

#include "Evector.h"

namespace Wstl{

// Estack 部分函数继承自Evector
tc
class Estack{

public:
    //构造函数
    Estack(T* data,int l){
        // 通过指针继承Evector类
        arr_ptr = data;
        ptr = new Evector<T>(data,l);
    }
    //析构函数
    ~Estack(){
        free(ptr);
        free(arr_ptr);
    }
public:
    // 各种成员函数
    int length(){
        return ptr->length();
    }
    // 删掉第一个元素
    int _pop(){
        return ptr->_pop();
    }
    // 压入一个元素
    int _push(T element){
        return ptr->_shift(element);
    }
    // 返回栈顶迭代器
    Iterators<T> _top(){
        return ptr->_begin();
    }
    // 返回栈底迭代器
    Iterators<T> _end(){
        return ptr->_end();
    }
private:
    T* arr_ptr;
    Evector<T> *ptr;
    int len = 0;
};
}

#endif // ESTACK_H
