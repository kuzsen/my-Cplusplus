#include<iostream>
using namespace std;
// 参考https://blog.csdn.net/weixin_52244492/article/details/124081709

int main()
{
	// 常量指针
	int a = 10, b = 20;
	const int *p = &a;
	cout << p << endl;
	p = &b; // 指针的地址可以改变，前后不一
	cout << p << endl;
	// *p = b; // 错误	C3892	“p” : 不能给常量赋值，所以指针的指向的内容不可以更改

	// 指针常量
	int c = 1, d = 2;
	int * const p2 = &c;
	cout << *p2 << endl; // 1
	*p2 = d;
	cout << *p2 << endl; // 2
	// p = &d; // 错误，指针的地址不可以修改

	system("pause");
	system("cls");
	return 0;
}
