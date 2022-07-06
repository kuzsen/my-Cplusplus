#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {

	/*std::move��һ���ǳ����Ի��Եĺ��������������ֵ���������������Ϊ���ܰ�һ��������������ƶ�����һ��������
	����ʵ��std::move�ƶ�����ʲô��Ψһ�Ĺ����ǰ���ֵǿ��ת��Ϊ��ֵ������ֵ���ÿ���ָ����ֵ��
	��ʵ�ֵ�ͬ��һ������ת����static_cast<T&&>(lvalue)�� 
	���ԣ�
	������
	std::move(xxx)��������������*/

	int a = 5; // a����ֵ��5����ֵ
	int& b = a;
	int&& c = move(a);
	cout << a << b << c; // a��Ȼ��5


	// ��vector��string���Ӧ�ó������Ӹ�std::move����õ��ƶ����庯�������������,ԭ��lvalueֵ��moved from֮��ֵ��ת��,���Ա�Ϊ��.
	std::string str = "Hello";
	std::vector<std::string> v;
	//���ó���Ŀ������캯�����½��ַ����飬��������
	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";
	//�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
	v.push_back(std::move(str));
	std::cout << "After move, str is \"" << str << "\"\n";
	std::cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";

	system("pause");
	system("cls");
	return 0;
}
