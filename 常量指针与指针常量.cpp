#include<iostream>
using namespace std;
// �ο�https://blog.csdn.net/weixin_52244492/article/details/124081709

int main()
{
	// ����ָ��
	int a = 10, b = 20;
	const int *p = &a;
	cout << p << endl;
	p = &b; // ָ��ĵ�ַ���Ըı䣬ǰ��һ
	cout << p << endl;
	// *p = b; // ����	C3892	��p�� : ���ܸ�������ֵ������ָ���ָ������ݲ����Ը���

	// ָ�볣��
	int c = 1, d = 2;
	int * const p2 = &c;
	cout << *p2 << endl; // 1
	*p2 = d;
	cout << *p2 << endl; // 2
	// p = &d; // ����ָ��ĵ�ַ�������޸�

	system("pause");
	system("cls");
	return 0;
}
