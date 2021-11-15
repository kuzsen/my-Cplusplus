#include<iostream>
using namespace std;

int bulbSwitch(int& n) {
	/*
	数学
链接：https://leetcode-cn.com/problems/bulb-switcher/solution/gong-shui-san-xie-jing-dian-shu-lun-tui-upnnb/
		
这是一道经典的数论题。

整理一下题意：第 i 轮改变所有编号为 i 的倍数的灯泡的状态（其中灯泡编号从 1 开始）。

一个编号为 x 的灯泡经过 n 轮后处于打开状态的充要条件为「该灯泡被切换状态次数为奇数次。
例如n = 4：
灯泡编号i		1	2	3	4

初始状态			0	0	0	0
第一轮后			1	1	1	1
第二轮后			1	0	1	0
第三轮后			1	0	0	0
第四轮后			1	0	0	1   =  结果是2
i状态切换次数	1	2	2	3		因为第1和第4个灯泡的状态都切换了奇数次

同时，一个灯泡切换状态的次数为其约数的个数（去重）。

于是问题转换为：在 [1,n]内有多少个数，其约数的个数为奇数。这些约数个数为奇数的灯泡就是最后亮着的灯泡。

又根据「约数」的定义，我们知道如果某个数 k 为 x 的约数，那么x/k 亦为 x 的约数，即「约数」总是成对出现，那么某个数的约数个数为奇数，意味着某个约数在分解过程中出现了 2次，且必然重复出现在同一次拆解中，即 k = x/k

 ，即有 x 为完全平方数（反之亦然）。

例如：4 = 1*4，或者4 = 2*2，那么4的约数为1/2/4 共3个 == 第4个灯泡状态切换次数3次， 所以编号4灯泡最终状态是亮着

问题最终转换为：在 [1,n]中是完全平方数的个数为多少。

		*/

	return (int)sqrt(n);//int取整比如2<根号6<3,取2
}

int main() {
	int n;
	while (cin>>n)
	{
		cout << bulbSwitch(n) << endl;
	}
	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
