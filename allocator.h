#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <malloc.h>
#include "Iterators.h"

namespace Wstl {

tc
// 内存管理器
// 继承自Iterators类
class allocators : public Iterators<T>{

public:
    // 构造函数
    allocators() : Iterators<T>(){};
public:
    // 新建内存空间
    T* _new(T* new_ptr){
        this->beused+=sizeof (T);
        if(isused(this->beused)){
            new_ptr = this->memory+beused;
        }
        else{
            // 内存已被占用，重新分配
            _new(new_ptr);
        }
        return new_ptr;
    }
    bool isused(int index){
        if(*(this->memory+index)==NULL){
            return true;
        }
        else{
            return false;
        }
    }
private:
    int beused = 0;
    int len = 0;
};

}

#endif // ALLOCATOR_H
