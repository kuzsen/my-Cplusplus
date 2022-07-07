#include <iostream>
#include <utility>
#include <vector>
#include <thread>
using namespace std;

void doit() {
	cout << "world" << endl;
}

template<class T> void changeVaule(T &x, T value) {
	x = value;
}

int main() {
	
	/*std::move是一个非常有迷惑性的函数，不理解左右值概念的人们往往以为它能把一个变量里的内容移动到另一个变量，
	但事实上std::move移动不了什么，唯一的功能是把左值强制转化为右值，让右值引用可以指向左值。
	其实现等同于一个类型转换：static_cast<T&&>(lvalue)。 
	所以，
	单纯的
	std::move(xxx)不会有性能提升*/
	/*
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
	*/
	
	/*
	thread a([] {
		cout << "hello" << endl;
	});
	thread b(doit);

	// 可能输出hello world， 也可能输出world hello
	// 多线程运行时是以异步方式执行的,在上面的例子中，我们定义了2个thread，这2个thread在执行时并不会按照一定的顺序。打个比方，2个thread执行时，就好比赛跑，谁先跑到终点，谁就先执行完毕。
	*/

	thread th[10];
	int nums[100];
	for (int i = 0; i < 100; i++) {
		// 原来thread在传递参数时，是以右值传递的：划重点：Args&&... args
		// 很明显的右值引用，那么我们该如何传递一个左值呢？std::ref和std::cref很好地解决了这个问题。
		// thread的方法传递引用的时候，必须外层用ref来进行引用传递，否则会编译出错。
		// 在用bind的时候，如果不用ref时，调用函数是没有引用的。是值传递，函数内部的修改对外面没有影响。
		// std::ref 可以包装按引用传递的值。  引用传递，函数内部的修改影响外面 
	    // std::cref 可以包装按const引用传递的值。  const引用传递，函数内部不能修改
		// 函数式编程（如std::bind）在使用时，是对参数直接拷贝，而不是引用。bind()是一个函数模板，它的原理是根据已有的模板，生成一个函数，但是由于bind()不知道生成的函数执行的时候，传递进来的参数是否还有效。所以它选择参数值传递而不是引用传递。如果想引用传递，std::ref和std::cref就派上用场了。

		th[i] = thread(changeVaule<int>, ref(nums[i]), i + 1);
	}

	for (int i = 0; i < 100; i++) {
		th[i].join();
		cout << nums[i] << endl;
	}
	system("pause");
	system("cls");
	return 0;
}
