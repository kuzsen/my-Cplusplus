#include<iostream>
using namespace std;
#include<thread>
#include<mutex> // �ֳƻ�������C++ 11���� Mutex ��ص��ࣨ���������ͣ��ͺ����������� <mutex>ͷ�ļ�
#include<condition_variable> // ������������������ص���ͺ���

mutex mymutex; // ȫ�ֻ�����
condition_variable cv; // ȫ�ֻ������
int flag = 0; // ȫ�ֱ�־λ
/*�� std::condition_variable�����ĳ��wait ���������õ�ʱ��
��ʹ�� std::unique_lock(ͨ�� std::mutex) ����ס��ǰ�̡߳�
��ǰ�̻߳�һֱ��������
ֱ������һ���߳�����ͬ�� std::condition_variable �����ϵ����� notification ���������ѵ�ǰ�߳�
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
	/*����˼��������߳�����Ӷ������÷�������������ʱ�����̣߳�һ���߳�����������У�������������������ǿ�����ʱ����һ���̣߳�������߳�������ɣ�����һ���߳��ڼ������С�*/
	th1.join();
	th2.join();
	th3.join();
	system("pause");
	system("cls");
	return 0;
}
