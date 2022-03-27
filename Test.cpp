/*
*   author: Wildpointer
*   date: 2022-3-27
*   about:关于Evector类成员函数的测试
*/
#include "Evector.h"

using namespace std;
using namespace Wstl;

int main(int argc, char *argv[]){
    printf("Evector Test\n");
    // 初始化数组
    int arr[5] = {12,1,2,3,4};
    // 初始化Evector
    Evector<int> e(arr,sizeof(arr)/sizeof(int));
    // 测试
    cout<<"length:"<<e.len<<endl;
    e._shift(1);
    e._push_back(9);
    e._pop();
    e._delete();
    e._replace(3,10);
    cout<<"Find:in address:"<<(e._find(9))<<endl;
    cout<<"end:"<<*(e._end()->memory)<<endl;
    auto iter = e._begin()->operator+(1);
    cout<<"begin:"<<(iter->memory)<<endl;
    auto iter2 = e._begin()+1;
    cout<<"begin:"<<(iter2->memory)<<endl;
    e.~Evector();
    system("pause");
    return 0;
}
