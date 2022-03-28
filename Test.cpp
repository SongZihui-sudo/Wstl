/*
*   author: Wildpointer
*   date: 2022-3-27
*   about:关于Evector类成员函数的测试
*/
#include "Estring.h"
#include "Evector.h"
#include "Estack.h"

using namespace std;
using namespace Wstl;

int Evector_test();
int Estring_test();
// main函数
int main(int argc, char *argv[]){
    cout<<"Wstl Test"<<endl;
    Evector_test();
    Estring_test();
    system("pause");
    return 0;
}
// 测试Evector
int Evector_test(){
    printf("Evector Test\n");
    // 初始化数组
    int arr[5] = {12,1,2,3,4};//11034
    // 初始化Evector
    Evector<int> ev(arr,sizeof(arr)/sizeof(int));
    // 测试Evector
    cout<<"length:"<<ev.len<<endl;
    ev._shift(15);
    ev._push_back(9);
    ev._pop();
    auto beg = ev._begin();
    cout<<"begin:"<<beg<<endl;
    ev._delete();
    ev._replace(3,10);
    cout<<"Find:in address:"<<(ev._find(9))<<endl;
    cout<<"end:"<<ev._end()<<endl;
    auto iter = ev._begin();
    cout<<"begin:"<<iter<<endl;
    iter = iter+1;
    cout<<"begin:"<<iter<<endl;
    auto begin = ev._begin();
    auto end = ev._end();
    cout<<"length:"<<ev.length()<<endl;
    while (begin!=end){
        begin = begin+1;
        cout<<"begin traverse test:"<<begin<<endl;
    }
    return 0;
}
// 测试Estring
int Estring_test(){
    // 测试Estring
    printf("Estring Test:\n");
    Estring es;
    es = "Hello World";
    cout<<"es:"<<es<<endl;
    auto begin = es._begin();
    auto end = es._end();
    cout<<"begin:"<<begin<<endl;
    cout<<"end:"<<end<<endl;
    cout<<"length:"<<es.length()<<endl;
    es._shift('a');
    es._push_back('E');
    cout<<"es:"<<es<<endl;
    cout<<"length:"<<es.length()<<endl;
    es._pop();
    es._delete();
    cout<<"length:"<<es.length()<<endl;
    while (begin!=end){
        begin = begin+1;
        cout<<"begin traverse test:"<<begin<<endl;
    }
    return  0;
}
