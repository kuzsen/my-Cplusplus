#include<iostream>
using namespace std;
void test1(int* p)
{
    *p = 50;    //�˴�Ӧ�������ж�p�Ƿ�Ϊ�գ�Ϊ�˲��Ե���Ҫ���˴�����û�ӡ�
    cout << p << endl;//p�ǵ�ַ
    cout << *p << endl;//*p = 10
    return;
}
void test2(int& p)
{
    p = 100;    //�˴�Ӧ�������ж�p�Ƿ�Ϊ�գ�Ϊ�˲��Ե���Ҫ���˴�����û�ӡ�
    return;
}
int main() {
    int a = 10;
    int* p = &a;
    cout << p << endl;//p�ǵ�ַ
    cout << *p << endl;//*p = 10
    test1(p);

    test2(a);
    cout << a << endl;
    system("pause");
    system("cls");
    return 0;
}