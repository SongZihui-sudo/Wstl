/*
*   author：Wildpointer
*   date：2022-3-27
*   about：迭代器的实现，思路见README.txt
*/
#ifndef ITERATORS_H
#define ITERATORS_H

#include <iostream>
#include "define.h"
#include <mutex>

using namespace std;

namespace Wstl{

//迭代器类
tc
class Iterators{

public:
//内存结点
struct memory_node{
    T* value; //当前内存块的地址
    memory_node* next; //相邻内存块的地址
};

public:
    //构造函数
    Iterators(int length,int num){
        this->link_list = new memory_node;
        this->link_list->next = NULL;
        this->index = num;
        this->real_size = length;
        this->memory = (T*)malloc(default_size*sizeof(T));
        if(!this->memory){
            printf("Wstl Error:Memory allocation failed.");
        }
        this->link_list->value = this->memory;
    };
    // 重载构造函数
    Iterators(T* pre,memory_node* link,int length,int num){
        this->index = num;
        this->real_size = length;
        this->link_list = link;
        this->memory = pre;
    }
    // 重载构造函数
    Iterators(){
        this->link_list = new memory_node;
        this->index = 0;
        this->link_list->next = NULL;
        this->real_size = 0;
        this->memory = (T*)malloc(default_size*sizeof(T));
        if(!this->memory){
            printf("Wstl Error:Memory allocation failed.");
        }
        this->link_list->value = this->memory;
    }
    //析构函数
    ~Iterators(){
        //释放内存空间
        this->memory = NULL;
        free(this->link_list);
        free(this->memory);
    };
public:
    //运算符重载+
    Iterators<T> operator+(int add){
        Iterators<T> ret(this->memory,this->link_list,this->real_size,this->index);
        ret.memory = this->memory+add;
        return  ret;
    };
    //运算符重载-
    Iterators<T> operator-(int sub){
        Iterators<T> ret(this->memory,this->link_list,this->real_size,this->index);
        ret.memory = this->memory-sub;
        return ret;
    };
    //运算符重载!=
    bool operator!=(Iterators<T> unequal){
        if(this->memory!=unequal.memory){
            return true;
        }
        else{
            return false;
        }
    };
    //运算符重载==
    bool operator==(Iterators<T> equal){
        if(this->memory==equal.memory){
            return true;
        }
        else{
            return false;
        }
    };
    // 运算符重载<<
    friend ostream & operator<<(ostream &out,Iterators<T> print){
        out<<*(print.memory);
        return out;
    };
    // add数组的默认大小100*sizof(T)个字节
    // 内存大小
    int len = default_size;
    // 长度
    int length(int l){
        return this->real_size = l;
    }
    // 重载返回长度
    int length(){
        return this->real_size;
    }
    // 调试输出全部的表
    int debug_print(){
        for(int i = 0;i < this->real_size;i++){
            cout<<*(this->memory+i)<<endl;
        }
        return 0;
    };
public:
    //内存基址
    T *memory;
    // 内存访问函数
    Iterators<T> visit(int ind){
        Iterators<T> ret(this->memory,this->link_list,this->real_size,this->index);
        // 超出当前内存块大小
        if(ind>this->len){
            int num = ind/this->len;
            memory_node *link = this->link_list;
            while(num){
                link = link->next;
                num--;
            }
            ret.memory = link->value+ind;
            free(link);
        }
        // 在当前内存块中
        else{
            ret.memory = this->memory+ind;
        }
        return  ret;
    }
    //内存不足时，拓展内存空间
    int expand_memory(){
        // 开辟新的内存块
        T* new_memory = (T*)malloc(default_size*sizeof (T));
        if(!new_memory){
            printf("Wstl Error:Memory allocation failed.");
        }
        memory_node *link = this->link_list;
        //找到最后一个节点
        while(link){
            link = link->next;
        }
        // 连接相邻的内存块
        link->value = new_memory;
        free(link);
        return 0;
    };
    // 内存块表
    memory_node* link_list;
private:
    // 数据的实际大小
    int real_size = 0;
    // 下表
    int index = 0;
};
}

#endif // ITERATORS_H
