#include<iostream>
using namespace std;
#include<thread>
#include<mutex> // 又称互斥量，C++ 11中与 Mutex 相关的类（包括锁类型）和函数都声明在 <mutex>头文件
#include<condition_variable> // 包含了与条件变量相关的类和函数

mutex mymutex; // 全局互斥锁
condition_variable cv; // 全局互斥变量
int flag = 0; // 全局标志位
/*当 std::condition_variable对象的某个wait 函数被调用的时候，
它使用 std::unique_lock(通过 std::mutex) 来锁住当前线程。
当前线程会一直被阻塞，
直到另外一个线程在相同的 std::condition_variable 对象上调用了 notification 函数来唤醒当前线程
*/
void printa() {
	unique_lock<mutex> lk(mymutex);
	int count = 0;
	while (count < 10) {
		while (flag != 0) cv.wait(lk);
		cout << "thread 1: a" << endl;
		flag = 1;
		cv.notify_all();
		count++;
	}
	cout << "my thread 1 finish" << endl;
}
void printb() {
	unique_lock<mutex> lk(mymutex);
	for (int i = 0; i < 10; i++) {
		while (flag != 1) cv.wait(lk);
		cout << "thread 2: b" << endl;
		flag = 2;
		cv.notify_all();
	}
	cout << "my thread 2 finish" << endl;
}
void printc() {
	unique_lock<mutex> lk(mymutex);
	for (int i = 0; i < 10; i++) {
		while (flag != 2) cv.wait(lk);
		cout << "thread 3: c" << endl;
		flag = 0;
		cv.notify_all();
	}
	cout << "my thread 3 finish" << endl;
}

int main()
{
	thread th1(printa);
	thread th2(printb);
	thread th3(printc);
	/*顾名思义就是往线程中添加东西；该方法可以用于临时加入线程，一个线程在运算过程中，如果满足于条件，我们可以临时加入一个线程，让这个线程运算完成，另外一个线程在继续运行。*/
	th1.join();
	th2.join();
	th3.join();
	system("pause");
	system("cls");
	return 0;
}
