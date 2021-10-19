//https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
//将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
//状态自动机
//复杂度分析
//
//时间复杂度：O(n)，其中 n 为字符串的长度。我们只需要依次处理所有的字符，处理每个字符需要的时间为 O(1)。
//
//空间复杂度：O(1)。自动机的状态只需要常数空间存储

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
//创建状态自动机类
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
	int sign = 1;//表示+  或者-
	long long ans = 0;//表示数字结果
	void get(char c)
	{
		state = allStateTable[state][stateNums(c)];
		if (state == "in_number")//字符c，为数字0-9，
		{
			ans = ans * 10 + (c - '0');//用字符转化为数字的时候经常要用到，比如要将‘8’转换为数字8，在语句中这样写就可以了，“ 8+‘0’”。这里的8就是数字
			//'9'-'0'=9;'8'-'0'=8;实现字符到数字的转化。原因是字符'0'~'9'的ascll上是相邻的
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);//若每次字符转换后加上  之前的  结果ans‘  超过32 位有符号整数，则取两端的值，即数据截断
		}
		else if (state == "signed")//中间遇到+/-  ？ ----解释，当state = “in_number”为时，他的下一状态值  只能是"in_number"   或者  "end"，√

			sign = c == '+' ? 1 : -1;
		//else if (state == "end")      // s - 123
		// main,    ans = 123也是正确的，所以这个不能用
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
	while (true)//while可以连续测试多种情况，很方便
	{
		getline(cin, s1);
		cout << myAtoi(s1) << endl;
	};

	system("pause");
	system("cls");
	return 0;
}