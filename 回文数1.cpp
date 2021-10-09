//https://blog.csdn.net/qq_41112170/article/details/108328453
//问题描述：
//当一个数从前往后写与从后往前写时相等，则该数被称为回文数，所有的个位数都是回文数。
//所有非回文数通过一系列的操作都可以匹配一个回文数。首先，将该数写反以后与原数相加，判断结果是否为回文数，如果不是，重复上述过程，直到和为回文数为止。例如：对于数67，两步以后可以将其转换为回文数，67 + 76 = 143， 143 + 341 = 484。
//给出一个正整数N，请你找出它所匹配的回文数以及它所经历的步骤数。

#include<iostream>
//#include<cmath>//数学头文件
using namespace std;
 
//将n倒转
int reverse(int n)
{
	int m = 0;
	while(n >0)
	{
		m = 10 * m + n % 10;
		n = n / 10;
	}
	return m;
}

//判断n是否是回文数（正反着读一样，如12321）
bool judge(int n)
{
	return (reverse(n) == n) ? true : false;
}

int main()
{
	int n, k, time = 0;//n为输入正整数，k为进行操作“判断n是否为回文数，如果不是，将该数倒转以后与原数相加
	cin >> n >> k;//数字间用空格隔开
	do {
		if (judge(n))
			break;
		time++;
		n += reverse(n);
	} while (time < k);//do...while....，while为循环条件，如果第K步之后未找到这个回文数，则输出第K步之后的结果和K来代替
	cout << time << "次匹配后得到的结果为：" << n << endl;

	system("pause");
	system("cls");
	return 0;
}

