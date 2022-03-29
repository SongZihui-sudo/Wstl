#ifndef ELIST_H
#define ELIST_H

#include  "allocator.h"

namespace Wstl{

tc
struct list_node{
    list_node<T> *next;
    T value;
    // 运算符重载<<
    friend ostream & operator<<(ostream &out,list_node<T> *print){
        out<<print->value;
        return out;
    };
};

tc
class Elist{

public:
    // 构造函数
    Elist(){
        ptr =new allocators<T>();
        // 新建一个节点
        this->head = new list_node<T>;
        this->head->value = 0;
        this->head->next = NULL;
    };
    // 析构函数
    ~Elist(){
        free(ptr);
    }
public:
    //相关成员函数
    // 从结尾插入
    int _push_back(T element){
        list_node<T> *node = new list_node<T>;
        node->value = element;
        node->next = NULL;
        list_node<T>* end =  this->_end();
        end->next = node;
        this->len++;
        return 0;
    }
    // 从开头插入
    int shift(T element){
        list_node<T> *node = new list_node<T>;
        node->value = element;
        node->next = NULL;
        list_node<T>* begin = this->_begin();
        head->next = node;
        node->next = begin;
        this->len++;
        return 0;
    }
    // 删除最后一个节点
    int _pop_back(){
        list_node<T>* end = this->_end();
        end->next = NULL;
        this->len--;
        return 0;
    }
    // 删除第一个节点
    int unshift(){
        list_node<T>* begin = this->_begin();
        this->head->next = this->head->next->next;
        begin = NULL;
        this->len--;
        return 0;
    }
    // 插入一个节点
    int _insert(int index,T element){
        list_node<T>* pre = this->visit(index);
        list_node<T>* cur = this->visit(index+1);
        list_node<T>* insert = new list_node<T>;
        insert->value = element;
        pre->next = insert;
        insert->next = cur;
        return 0;
    }
    // 节点访问
    list_node<T>* visit(int index){
        if(index>this->len){
            //return static_cast<int>(-1);
        }
        else{
            list_node<T>* head_ptr = this->head;
            while (index){
                head_ptr = head_ptr->next;
                index--;
            }
            return head_ptr;
        }
    }
    // 查找找一个节点
    list_node<T>* _find(T element){
        list_node<T>* head_ptr = this->head;
        while (head_ptr) {
            if(head_ptr->value == element){
                return head_ptr;
            }
            head_ptr = head_ptr->next;
        }
    }
    // 最后一个节点
    list_node<T>* _end(){
        list_node<T> *end = this->head;
        int i = this->len;
        while (i) {
            end = end->next;
            i--;
        }
        return end;
    }
    // 第一个节点
    list_node<T>* _begin(){
        list_node<T> *begin = this->head->next;
        return  begin;
    }
    // 长度
    int length(){
        return this->len;
    }
public:
    // 运算符重载+
    list_node<T>* operator+(int index){
        return this->visit(index);
    }
private:
    int len = 0;
    allocators<T>* ptr;
    list_node<T> *head;
};
}


#endif // ELIST_H
