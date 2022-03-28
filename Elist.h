#ifndef ELIST_H
#define ELIST_H

#include  "allocator.h"

namespace Wstl{

tc
struct list_node{
    list_node<T> *next;
    T value;
};

tc
class Elist{

public:
    // 构造函数
    Elist(){
        ptr =new allocators<T>();
    };
    // 析构函数
    ~Elist(){

    }
public:
    //相关成员函数
private:
    int len = 0;
    allocators<T>* ptr;
};
}


#endif // ELIST_H
