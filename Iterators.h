#ifndef ITERATORS_H
#define ITERATORS_H

#include <iostream>
#include <malloc.h>
#include "define.h"

using namespace std;

namespace Wstl{
//内存结点
tc
struct memory_node{
    T value;
    int* start;//当前节点的地址
    int length;//长度
};
//迭代器类
tc
class Iterators{
public:
    //构造函数
    Iterators(int length){
        real_size = length;
        memory_node<T> *node = new memory_node<T>;
        memory = (T*)malloc(default_size*sizeof(T));
        if(!memory){
            printf("Wstl Error:Memory allocation failed.");
        }
    };
    //析构函数
    ~Iterators(){
        //释放内存空间
        memory = NULL;
        free(memory);
    };
public:
    //内存不足时，拓展内存空间
    int expand_memory(){
        return 0;
    };
public:
    //运算符重载+
    Iterators<T> operator+(const int add){
        return  *(memory+add);
    };
    //运算符重载-
    Iterators<T> operator-(const int sub){
        return *(memory+sub);
    }
    //内存基址
    T *memory;
    // add数组的默认大小100*sizof(T)个字节
    // 内存大小
    int len = default_size;
    // 长度
    int length(int l){
        return real_size = l;
    }
    // 重载返回长度
    int length(){
        return real_size;
    }
    // 调试输出全部的表
    int debug_print(){
        for(int i = 0;i < real_size;i++){
            cout<<*(memory+i)<<endl;
        }
    };
private:
    // 数据的实际大小
    int real_size = 0;
};
}

#endif // ITERATORS_H
