//https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
//���ַ���ת����һ�� 32 λ�з������������� C/C++ �е� atoi ��������
//״̬�Զ���
//���Ӷȷ���
//
//ʱ�临�Ӷȣ�O(n)������ n Ϊ�ַ����ĳ��ȡ�����ֻ��Ҫ���δ������е��ַ�������ÿ���ַ���Ҫ��ʱ��Ϊ O(1)��
//
//�ռ临�Ӷȣ�O(1)���Զ�����״ֻ̬��Ҫ�����ռ�洢

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
//����״̬�Զ�����
class Automation
{
	string state = "start";
	unordered_map<string, vector<string>> allStateTable =
	{
		{"start",            {"start", "signed", "in_number", "end"}},
		{"signed",        {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end", "in_number", "end"}},
		{"end",             {"end", "end", "end", "end"}}
	};

	int stateNums(char c)
	{
		if (isspace(c))  return 0;
		if (c == '+' || c == '-')  return 1;
		if (isdigit(c))  return 2;
		return 3;
	}

public:
	int sign = 1;//��ʾ+  ����-
	long long ans = 0;//��ʾ���ֽ��
	void get(char c)
	{
		state = allStateTable[state][stateNums(c)];
		if (state == "in_number")//�ַ�c��Ϊ����0-9��
		{
			ans = ans * 10 + (c - '0');//���ַ�ת��Ϊ���ֵ�ʱ�򾭳�Ҫ�õ�������Ҫ����8��ת��Ϊ����8�������������д�Ϳ����ˣ��� 8+��0�����������8��������
			//'9'-'0'=9;'8'-'0'=8;ʵ���ַ������ֵ�ת����ԭ�����ַ�'0'~'9'��ascll�������ڵ�
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);//��ÿ���ַ�ת�������  ֮ǰ��  ���ans��  ����32 λ�з�����������ȡ���˵�ֵ�������ݽض�
		}
		else if (state == "signed")//�м�����+/-  �� ----���ͣ���state = ��in_number��Ϊʱ��������һ״ֵ̬  ֻ����"in_number"   ����  "end"����

			sign = c == '+' ? 1 : -1;
		//else if (state == "end")      // s - 123
		// main,    ans = 123Ҳ����ȷ�ģ��������������
		//	ans = 0;
	}
};
int myAtoi(string s)
{
	Automation automation;
	for (auto c : s)
	{
		automation.get(c);
	}
	return automation.sign * automation.ans;
}
int main()
{
	string s1;
	while (true)//while�����������Զ���������ܷ���
	{
		getline(cin, s1);
		cout << myAtoi(s1) << endl;
	};

	system("pause");
	system("cls");
	return 0;
}