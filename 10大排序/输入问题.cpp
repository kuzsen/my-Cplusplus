#include<iostream>
#include <vector>
#include <string>
using namespace std;

void func(char arr[100]) {
	cout << sizeof(arr); // 8�� ��ʱ��arrΪ�����ָ�룬64Ϊϵͳ�£�ָ���СΪ8
}
int main()
{
	string s = "100,20,311,4,5";
	
	vector<int> arr;
	int i = 0;
	while (i < s.size()) {
		int j = i + 1;
		while (j < s.size() && s[j] != ',') j++;
		string cur = s.substr(i, j - 1 - i + 1);
		int num = stoi(cur);
		arr.push_back(num);
		cout << num << endl;
		i = j + 1;
	}
	char str[] = "abcdg";
	cout << sizeof(str) << endl; // 6��'\n'Ҳ��һ���ַ�
	func(str);
	system("pause");
	system("cls");
	return 0;
}

