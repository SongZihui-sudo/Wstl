/*
*   author:Wildpointer
*   date:2022-3-27
*   about:Estring类的实现
*/
#ifndef ESTRING_H
#define ESTRING_H

#include "Iterators.h"
#include <string.h>
#include "Evector.h"

namespace   Wstl{
// Estring类继承自Evector类
class   Estring{
private:
    Evector<char>* ptr;
    int len = 0;
    char* str_ptr;
public:
    //构造函数
    Estring(){
        // 通过指针继承Evector类
        this->ptr = new Evector<char>();
    };
    //析构函数
    ~Estring(){
        free(this->ptr);
    };
public:
    // 类内函数
    int length(){
        return this->ptr->length();
    };
    // 返回第一个元素的迭代器
    Iterators<char> _begin(){
        return this->ptr->_begin();
    };
    // 返回最后一个节点的迭代器
    Iterators<char> _end(){
        return this->ptr->_end();
    };
    // 直接继承Evector的成员函数
    int _shift(char element){
        return this->ptr->_shift(element);
    }
    int _pop(){
        return this->ptr->_pop();
    }
    int _push_back(char elelment){
        return this->ptr->_push_back(elelment);
    }
    int _delete(){
        return this->ptr->_delete();
    }
    int _replice(int index,char element){
        return this->ptr->_replace(index,element);
    }
    char _find(char element){
        return this->_find(element);
    }
    // 运算符重载 =
    char* operator=(const char* str){
        this->str_ptr = const_cast<char *>(str);
        this->ptr->len = strlen(str_ptr);
        this->ptr->public_ptr->length(ptr->len);
        // 拷贝进迭代器内存
        this->ptr->memory_copy(str_ptr);
        return  str_ptr;
    };
    // 运算符重载 <<
    friend ostream & operator<<(ostream &out,Estring &print){
        out<<print.ptr->public_ptr->memory;
        return out;
    };
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
