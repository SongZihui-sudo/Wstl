/*
*   author：Wildpointer
*   date：2022-3-27
*   about：迭代器的实现，思路见README.txt
*/
#ifndef ITERATORS_H
#define ITERATORS_H

#include <iostream>
#include <malloc.h>
#include "define.h"

using namespace std;

namespace Wstl{

//迭代器类
tc
class Iterators{

private:
//内存结点
struct memory_node{
    T* value; //当前内存块的地址
    memory_node* next; //相邻内存块的地址
};
public:
    //构造函数
    Iterators(int length,int num){
        link_list = new memory_node;
        link_list->next = NULL;
        index = num;
        real_size = length;
        memory_node *node = new memory_node;
        memory = (T*)malloc(default_size*sizeof(T));
        if(!memory){
            printf("Wstl Error:Memory allocation failed.");
        }
        link_list->value = memory;
    };
    // 重载构造函数
    Iterators(T* pre,memory_node* link,int length,int num){
        index = num;
        real_size = length;
        link_list = link;
        memory = pre;
    }
    //析构函数
    ~Iterators(){
        //释放内存空间
        memory = NULL;
        free(link_list);
        free(memory);
    };
public:
    //内存不足时，拓展内存空间
    int expand_memory(){
        // 开辟新的内存块
        T* new_memory = (T*)malloc(default_size*sizeof (T));
        if(!new_memory){
            printf("Wstl Error:Memory allocation failed.");
        }
        memory_node *link = link_list;
        //找到最后一个节点
        while(link){
            link = link->next;
        }
        // 连接相邻的内存块
        link->value = new_memory;
        free(link);
        return 0;
    };
    // 内存访问函数
    Iterators<T>* visit(int index){
        Iterators<T> *ret = new Iterators(memory,link_list,real_size,index);
        // 超出当前内存块大小
        if(index>len){
            int num = index/len;
            memory_node *link = link_list;
            while(num){
                link = link->next;
                num--;
            }
            ret->memory = link->value+index;
            free(link);
        }
        // 在当前内存块中
        else{
            ret->memory = memory+index;
        }
        return  ret;
    }
public:
    //运算符重载+
    Iterators<T>* operator+(const int &add){
        Iterators<T>* ret = new Iterators(memory,link_list,real_size,index);
        ret->memory = memory+add;
        return  ret;
    };
    //运算符重载-
    Iterators<T>* operator-(const int &sub){
        Iterators<T>* ret = new Iterators(memory,link_list,real_size,index);
        ret->memory = memory-sub;
        return ret;
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
    // 下表
    int index = 0;
    // 内存块表
    memory_node* link_list;
};
}

#endif // ITERATORS_H
