/*
*   author:Wildpointer
*   date:2022-3-27
*   about:Estring类的实现
*/
#ifndef ESTRING_H
#define ESTRING_H

#include "Iterators.h"
#include <string.h>

namespace   Wstl{

class   Estring{
private:
    Iterators<char>* ptr;
    int len = 0;
    char* str_ptr;
public:
//构造函数
    Estring(){
        // 创建一个迭代器ptr
        ptr = new Iterators<char>(this->len,0);
        // 拷贝进迭代器缓存
        memory_copy(str_ptr);
        this->len = strlen(str_ptr);
    };
    //析构函数
    ~Estring(){
        free(ptr);
    };
public:
    // 类内函数
    int length(){
        return this->len;
    };
    // 返回第一个元素的迭代器
    Iterators<char> _begin(){
        return ptr->visit(0);
    };
    // 返回最后一个节点的迭代器
    Iterators<char> _end(){
        return ptr->visit(this->len);
    };
    // 运算符重载 =
    char* operator=(const char* str){
        return  this->str_ptr = const_cast<char *>(str);
    };
    // 运算符重载 <<
    friend ostream & operator<<(ostream &out, Estring &str){
        out<<str.str_ptr;
        return out;
    };
    //内存拷贝
    int memory_copy(char *src){
        if(this->len==0){
            //长度为零，直接退出
            return -1;
        }
        else if (this->len>this->ptr->length()) {
            //拓展内存之后递归
            this->ptr->expand_memory();
            memory_copy(src);
        }
        else{
            //防止内存重叠
            if((src)<(this->ptr->memory)||(src)>(this->ptr->memory)){
                for(int i = 0;i < this->len;i++){
                    *(this->ptr->memory+i) = *(src+i);
                }
            }
            //内存冲突
            else{
                for(int i = this->len;i>0;i--){
                    *(this->ptr->memory+i) = *(src+i);
                }
            }
        };
        //debug_print(this->ptr->memory);
        return 0;
    }
private:
    //debugger 输出 内容
    int debug_print(char *beg){
        for(int i = 0;i < this->len;i++){
            cout<<"data:"<<*(beg+i)<<endl;
        }
        return 0;
    };
    int debug_print_address(char *beg){
        for(int i = 0;i < this->len;i++){
            cout<<"data:"<<beg+i<<endl;
        }
        return 0;
    }
};
}

#endif // ESTRING_H
