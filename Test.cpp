//
//  author: Wildpointer
//  date: 2022-3-27
//  about:关于Wstl的测试
//
#include "Estring.h"
#include "Evector.h"
#include "Estack.h"
#include "Elist.h"
#include "piece_table.h"

using namespace std;
using namespace Wstl;

int Evector_test();
int Estring_test();
int Estack_test();
int Elist_test();
int piece_table_test();

// main函数
int main(int argc, char *argv[]){
    cout<<"Wstl Test"<<endl;
    Evector_test();
    Estring_test();
    Estack_test();
    Elist_test();
    piece_table_test();
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
// 测试Estack
int Estack_test(){
    printf("Estack Test:\n");
    int arr[5] = {1,2,3,4,5};
    Estack<int> ek(arr,sizeof (arr)/sizeof (int));
    cout<<"length:"<<ek.length()<<endl;
    ek._push(10);
    cout<<"top:"<<ek._top()<<endl;
    ek._pop();
    cout<<"top:"<<ek._top()<<endl;
    cout<<"end:"<<ek._end()<<endl;
    return 0;
}
// 测试Elist
int Elist_test(){
    printf("Elist Test:\n");
    Elist<int> el;
    el.shift(99);
    auto begin = el._begin();
    cout<<"begin:"<<begin<<endl;
    el._push_back(9);
    auto end = el._end();
    cout<<"end:"<<end<<endl;
    el._insert(1,10);
    cout<<"length:"<<el.length()<<endl;
    el._pop_back();
    el.unshift();
    auto begin2 = el._begin();
    auto end2 = el._end();
    cout<<"begin:"<<begin2<<endl;
    cout<<"end:"<<end2<<endl;
    return 0;
}
// 测试piece_table
int piece_table_test(){
    printf("Piece table Test:");
    piece_table<char> p;
    p._push_back('a');
    p._push_back('b');
    p._insert(1,'d');
    auto begin = p._begin();
    auto end = p._end();
    cout<<"length:"<<p.length()<<endl;
    return 0;
}
