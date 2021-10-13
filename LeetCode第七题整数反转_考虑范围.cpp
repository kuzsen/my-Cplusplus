
//https://leetcode-cn.com/problems/reverse-integer/solution/tu-jie-7-zheng-shu-fan-zhuan-by-wang_ni_ma/
// 详细题解分析
// 
// 
//"整数反转"题目描述：
//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
//如果<<反转后>>整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。
//
//假设环境不允许存储 64 位整数（有符号或无符号），即不能用  长整型数据long （int）
//int型：32位整型，取值范围为 - 2 ^ 31 ~(2 ^ 31 - 1) .
//long：在32位系统是32位整型, 取值范围为 - 2 ^ 31 ~(2 ^ 31 - 1)；在64位系统是64位整型, 取值范围为 - 2 ^ 63 ~(2 ^ 63 - 1)

#include<iostream>
using namespace std;
int Reverse(int& n) 
{
	int res = 0;//定义输出结果resul
	while (n != 0)
	{
		int temp = n % 10;//定义n的个位数/余数
		//判断是否大于  最大32位整数2147483647
		if (res > 214748364 || (res == 214748364 && temp > 7))
		{
			cout << "您输入整数反转后会大于最大32位整数" << endl;
			return 0;
		}
		//判断是否小于  最小32位整数-2147483648
		if (res < -214748364 || (res == -214748364 && temp < -8))
		{
			cout << "您输入整数反转后会小于最小32位整数" << endl;
			return 0;
		}

		res = res * 10 + temp;
		n = n / 10;
	}
	return res;
}

int main()
{
	int test = 2147483646;
	cout << Reverse(test) << endl;

	system("pause");
	system("cls");
	return 0;
}