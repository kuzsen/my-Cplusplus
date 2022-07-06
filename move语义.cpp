#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {

	/*std::move是一个非常有迷惑性的函数，不理解左右值概念的人们往往以为它能把一个变量里的内容移动到另一个变量，
	但事实上std::move移动不了什么，唯一的功能是把左值强制转化为右值，让右值引用可以指向左值。
	其实现等同于一个类型转换：static_cast<T&&>(lvalue)。 
	所以，
	单纯的
	std::move(xxx)不会有性能提升*/

	int a = 5; // a是左值，5是右值
	int& b = a;
	int&& c = move(a);
	cout << a << b << c; // a依然是5


	// 在vector和string这个应用场景，加个std::move会调用到移动语义函数，避免了深拷贝,原左lvalue值被moved from之后值被转移,所以变为空.
	std::string str = "Hello";
	std::vector<std::string> v;
	//调用常规的拷贝构造函数，新建字符数组，拷贝数据
	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";
	//调用移动构造函数，掏空str，掏空后，最好不要使用str
	v.push_back(std::move(str));
	std::cout << "After move, str is \"" << str << "\"\n";
	std::cout << "The contents of the vector are \"" << v[0]
		<< "\", \"" << v[1] << "\"\n";

	system("pause");
	system("cls");
	return 0;
}
