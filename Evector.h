#ifndef EVECTOR_H
#define EVECTOR_H
#include <iostream>

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
        len = length;
        // 创建一个迭代器
        ptr = new Iterators<T>(len);
        // 向迭代器缓存中拷贝数据
        memory_copy(arr);
    };
    // 析构函数
    ~Evector(){
        //释放迭代器
        ptr->~Iterators();
        arr = NULL;
    };
// 数据结构操作
public:
    //首个元素的头迭代器
    T* _begin(){
        return  *(ptr->memory);
    };
    //最后一个节点的尾迭代器
    T* _end(){
        return *(ptr->memory+len);
    };
    //向第一位插入元素
    int _shift(T element){
        if((sizeof(T)*(len+1))>ptr->len*sizeof (T)){
            printf("Wstl ERROR:Out of memory.");
            ptr->expand_memory();
            _shift(element);
        }
        else{
            for(int i = len;i > 0;i--){
                if(i-1<0){
                    break;
                }
                *(ptr->memory+i) = *(ptr->memory+i-1);
            }
            *(ptr->memory) = element;
        }
        len++;
        ptr->length(len);
        //debug_print(ptr->memory);
    };
    //删除第一个元素
    int _pop(){
        *(ptr->memory) = NULL;
        //向前移动
        for(int i = 1;i < len;i++){
            if(i+1>len){
                break;
            }
            *(ptr->memory+i-1) = *(ptr->memory+i);
        }
        len--;
        //dp
        return 0;
    };
    //删除最后一个元素
    int _delete(){
        *(ptr->memory+len-1) = NULL;
        len--;
        ptr->length(len);
        //dp
        return 0;
    };
    //从尾部添加一个元素
    int _push_back(T element){
        if((sizeof(T)*(len+1))>ptr->len*sizeof (T)){
            printf("Wstl ERROR:Out of memory.");
            ptr->expand_memory();
            _push_back(element);
        }
        else{
            *(ptr->memory+len) = element;
        }
        len++;
        ptr->length(len);
        //debug_print(ptr->memory);
        return 0;
    };
    //向指定位置后插入元素
    int _replace(int num,int element){
        if((sizeof(T)*(len+1))>ptr->len*sizeof (T)){
            printf("Wstl ERROR:Out of memory.");
            ptr->expand_memory();
            _replace(num,element);
        }
        else{
            T *address = _find(num);
            if(address!=NULL){
                len++;
                int index =len - (address-ptr->memory)/(sizeof (T));
                for(int i = len; i > index;i++){
                    if(i-1<0){
                        break;
                    }
                    *(ptr->memory+i) = *(ptr->memory+i-1);
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
        for(int i = 0;i < len;i++){
            for(int j= len;j > 0;j--){
                if(*(ptr->memory+i)==element){
                    return ptr->memory+i;
                }
                else if(*(ptr->memory+j)==element){
                    return  ptr->memory+j;
                }
            }
        }
        return NULL;
    };
//内存操作
public:
    //内存拷贝
    int memory_copy(T *src){
        if(len==0){
            //长度为零，直接退出
            printf("Wstl Error:Length can not be 0.");
            return -1;
        }
        else if (len>ptr->length()) {
            //拓展内存之后递归
            ptr->expand_memory();
            memory_copy(src);
        }
        else{
            int l = len;
            //防止内存重叠
            if((src)<(ptr->memory)||(src)>(ptr->memory)){
                for(int i = 0;i < len;i++){
                    *(ptr->memory+i) = *(src+i);
                }
            }
            //内存冲突
            else{
                for(int i = len;i>0;i--){
                    *(ptr->memory+i) = *(src+i);
                }
            }
        };
        //debug_print(ptr->memory);
        return 0;
    }
private:
    T *arr;
    //创建一个迭代器
    Iterators<T> *ptr;
private:
    //debugger 输出
    int debug_print(T *beg){
        for(int i = 0;i < len;i++){
            cout<<"data:"<<*(beg+i)<<endl;
        }
    };
};
}
#endif // EVECTOR_H
