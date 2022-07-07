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
	
	/*std::move��һ���ǳ����Ի��Եĺ��������������ֵ���������������Ϊ���ܰ�һ��������������ƶ�����һ��������
	����ʵ��std::move�ƶ�����ʲô��Ψһ�Ĺ����ǰ���ֵǿ��ת��Ϊ��ֵ������ֵ���ÿ���ָ����ֵ��
	��ʵ�ֵ�ͬ��һ������ת����static_cast<T&&>(lvalue)�� 
	���ԣ�
	������
	std::move(xxx)��������������*/
	/*
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
	*/
	
	/*
	thread a([] {
		cout << "hello" << endl;
	});
	thread b(doit);

	// �������hello world�� Ҳ�������world hello
	// ���߳�����ʱ�����첽��ʽִ�е�,������������У����Ƕ�����2��thread����2��thread��ִ��ʱ�����ᰴ��һ����˳�򡣴���ȷ���2��threadִ��ʱ���ͺñ����ܣ�˭���ܵ��յ㣬˭����ִ����ϡ�
	*/

	thread th[10];
	int nums[100];
	for (int i = 0; i < 100; i++) {
		// ԭ��thread�ڴ��ݲ���ʱ��������ֵ���ݵģ����ص㣺Args&&... args
		// �����Ե���ֵ���ã���ô���Ǹ���δ���һ����ֵ�أ�std::ref��std::cref�ܺõؽ����������⡣
		// thread�ķ����������õ�ʱ�򣬱��������ref���������ô��ݣ������������
		// ����bind��ʱ���������refʱ�����ú�����û�����õġ���ֵ���ݣ������ڲ����޸Ķ�����û��Ӱ�졣
		// std::ref ���԰�װ�����ô��ݵ�ֵ��  ���ô��ݣ������ڲ����޸�Ӱ������ 
	    // std::cref ���԰�װ��const���ô��ݵ�ֵ��  const���ô��ݣ������ڲ������޸�
		// ����ʽ��̣���std::bind����ʹ��ʱ���ǶԲ���ֱ�ӿ��������������á�bind()��һ������ģ�壬����ԭ���Ǹ������е�ģ�壬����һ����������������bind()��֪�����ɵĺ���ִ�е�ʱ�򣬴��ݽ����Ĳ����Ƿ���Ч��������ѡ�����ֵ���ݶ��������ô��ݡ���������ô��ݣ�std::ref��std::cref�������ó��ˡ�

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
