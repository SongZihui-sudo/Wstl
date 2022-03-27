/*
*   author：Wildpointer
*   date： 20022-3-27
*   about： 关于Evector类的实现
*/
#ifndef EVECTOR_H
#define EVECTOR_H
#include "Iterators.h"

using namespace std;
// Wstl命名空间
namespace Wstl{
// Evector
tc
class Evector{
public:
    int len;
// 类
public:
    // 构造函数
    Evector(T *arr_ptr,int length){
        arr = arr_ptr;
        this->len = length;
        // 创建一个迭代器
        this->ptr = new Iterators<T>(this->len,0);
        // 向迭代器缓存中拷贝数据
        memory_copy(arr);
        // 测试
        dpa
    };
    // 析构函数
    ~Evector(){
        //释放迭代器
        this->ptr->~Iterators();
        arr = NULL;
    };
// 数据结构操作
public:
    //首个元素的头迭代器
    Iterators<T>* _begin(){
        return  this->ptr->visit(0);
    };
    //最后一个节点的尾迭代器
    Iterators<T>* _end(){
        return  this->ptr->visit(this->len);
    };
    //向第一位插入元素
    int _shift(T element){
        if((sizeof(T)*(this->len+1))>this->ptr->len*sizeof (T)){
            printf("Wstl ERROR:Out of memory.");
            this->ptr->expand_memory();
            _shift(element);
        }
        else{
            for(int i = this->len+1;i > 0;i--){
                if(i-1<0){
                    break;
                }
                *(this->ptr->memory+i) = *(this->ptr->memory+i-1);
            }
            *(this->ptr->memory) = element;
        }
        this->len++;
        this->ptr->length(this->len);
        //dp
        //debug_print(this->ptr->memory);
    };
    //删除第一个元素
    int _pop(){
        *(this->ptr->memory) = NULL;
        //向前移动
        for(int i = 2;i < this->len;i++){
            if(i+1>this->len){
                break;
            }
            *(this->ptr->memory+i-1) = *(this->ptr->memory+i);
        }
        this->len--;
        //dp
        return 0;
    };
    //删除最后一个元素
    int _delete(){
        *(this->ptr->memory+this->len-1) = NULL;
        this->len--;
        //dp
        return 0;
    };
    //从尾部添加一个元素
    int _push_back(T element){
        if((sizeof(T)*(this->len+1))>this->ptr->len*sizeof (T)){
            printf("Wstl ERROR:Out of memory.");
            this->ptr->expand_memory();
            _push_back(element);
        }
        else{
            *(this->ptr->memory+this->len) = element;
        }
        this->len++;
        this->ptr->length(this->len);
        //debug_print(this->ptr->memory);
        //dp
        return 0;
    };
    //向指定位置后插入元素
    int _replace(int num,int element){
        if((sizeof(T)*(this->len+1))>this->ptr->len*sizeof (T)){
            printf("Wstl ERROR:Out of memory.");
            this->ptr->expand_memory();
            _replace(num,element);
        }
        else{
            T *address = _find(num);
            if(address!=NULL){
                this->len++;
                int index =this->len - (address-this->ptr->memory)/(sizeof (T));
                for(int i = this->len; i > index;i++){
                    if(i-1<0){
                        break;
                    }
                    *(this->ptr->memory+i) = *(this->ptr->memory+i-1);
                }
                *(address) = element;
            }
            else{
                printf("Wstl ERROR:NOT FOUND.");
                return -1;
            }
        }
        //dp;
        return 0;
    };
    //查找
    T* _find(T element){
        for(int i = 0;i < this->len;i++){
            for(int j= this->len;j > 0;j--){
                if(*(this->ptr->memory+i)==element){
                    return this->ptr->memory+i;
                }
                else if(*(this->ptr->memory+j)==element){
                    return  this->ptr->memory+j;
                }
            }
        }
        return NULL;
    };
    //长度
    int length(){
        return this->len-1;
    }
//内存操作
public:
    //内存拷贝
    int memory_copy(T *src){
        if(this->len==0){
            //长度为零，直接退出
            printf("Wstl Error:Length can not be 0.");
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
    T *arr;
    //创建一个迭代器
    Iterators<T> *ptr;
private:
    //debugger 输出 内容
    int debug_print(T *beg){
        for(int i = 0;i < this->len;i++){
            cout<<"data:"<<*(beg+i)<<endl;
        }
        return 0;
    };
    int debug_print_address(T *beg){
        for(int i = 0;i < this->len;i++){
            cout<<"data:"<<beg+i<<endl;
        }
        return 0;
    }
};
}
#endif // EVECTOR_H
