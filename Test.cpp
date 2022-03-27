/*
*   author: Wildpointer
*   date: 2022-3-27
*   about:关于Evector类成员函数的测试
*/
#include "Evector.h"
#include "Estring.h"

using namespace std;
using namespace Wstl;

int main(int argc, char *argv[]){
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
    cout<<"begin:"<<*(beg->memory)<<endl;
    ev._delete();
    ev._replace(3,10);
    cout<<"Find:in address:"<<(ev._find(9))<<endl;
    cout<<"end:"<<*(ev._end()->memory)<<endl;
    auto iter = ev._begin()->operator+(1);
    cout<<"begin:"<<(iter->memory)<<endl;
    auto iter2 = ev._begin()+1;
    cout<<"begin:"<<(iter2->memory)<<endl;
    auto begin = ev._begin();
    int i = 0;
    cout<<"length:"<<ev.length()<<endl;
    while (i<ev.length()) {
        begin = begin->operator+(1);
        cout<<"traverse test:"<<*(begin->memory)<<endl;
        i++;
    }
    ev.~Evector();
    // 测试Estring
    system("pause");
    return 0;
}
