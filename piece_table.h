//
//  author:Wildpointer
//  date:2022-3-29
//  about: piece table 的实现
//
#ifndef PIECE_TABLE_H
#define PIECE_TABLE_H

#include "Iterators.h"
#include "Estring.h"
#include "Elist.h"
#include "allocator.h"

namespace Wstl {

tc
class piece_table{

private:

//piece table 节点
struct node{
    int start;
    Estring type;
    int length;
    node* next;
};

public:
    // 构造函数
    piece_table(){
        this->memory_ptr = new allocators<T>();
    }
    // 析构函数
    ~piece_table(){
        free(this->ptr);
    }
public:
    // 返回长度
    int length(){
        return this->len;
    }
    // 返回第一个节点
    Iterators<T> _begin(){
        return this->table._begin();
    }
    // 返回最后一个节点
    Iterators<T> _end(){
        return this->table._end();
    }
    // 添加一个节点
    int _push_back(T element){
        // 新建一个节点
        node* piece_node = new node();
        piece_node->type = "add";
        piece_node->start = this->len;
        piece_node->length = 1;
        add._push_back(element);
        this->len = this->add.len;
        this->table._push_back(piece_node);
        return 0;
    }
    // 插入一个节点
    int _insert(int index,T element){
        // 新建一个节点
        node* piece_node = new node();
        piece_node->type = "add";
        piece_node->start = this->len;
        piece_node->length = 1;
        add._push_back(element);
        this->len = this->add.len;
        this->table._insert(index,piece_node);
        return 0;
    }
private:
    Iterators<T> *ptr;
    allocators<T> *memory_ptr;
    int len = 0;
    Elist<T> table;
    int size = default_size;
    Evector<T> add;
};

}

#endif // PIECE_TABLE_H
