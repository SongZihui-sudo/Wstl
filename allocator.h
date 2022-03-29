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
        if(this->beused<=default_size){
            if(isused(this->beused)){
                new_ptr = this->memory+beused;
            }
            else{
                // 内存已被占用，重新分配
                _new(new_ptr);
            }
            return new_ptr;
        }
        else{
            int index = new_ptr/(this->memory+default_size);
            auto link = this->link_list;
            while (index) {
                link = link->next;
                index--;
            }
            new_ptr = this->link->value+(new_ptr-this->memory+default_size);
            return new_ptr;
        }

    }
    // 内存是否被占用
    bool isused(int index){
        if(*(this->memory+index)==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    // 删除内存
    bool _delete(T* delete_ptr){
        *(delete_ptr) = NULL;
        this->beused = this->beused - sizeof (T);
        if(beused<0){
            beused = 0;
            return false;
        }
        else{
            return true;
        }
    }
private:
    int beused = 0;
    int len = 0;
};

}

#endif // ALLOCATOR_H
