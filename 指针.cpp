#include<iostream>
using namespace std;
void test1(int* p)
{
    *p = 52125;    //此处应该首先判断p是否为空，为了测试的需要，此处我们没加。
    cout << p << endl;//p是地址
    cout << *p << endl;//*p = 10
    return;
}
void test2(int& p)
{
    p = 100;    //此处应该首先判断p是否为空，为了测试的需要，此处我们没加。
    return;
}
int main() {
    int a = 10;
    int* p = &a;
    cout << p << endl;//p是地址
    cout << *p << endl;//*p = 10
    test1(p);

    test2(a);
    cout << a << endl;
    system("pause");
    system("cls");
    return 0;
}
