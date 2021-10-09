//给出一道数组，然后求出长度为n的和为偶数子序列个数。
//比如说数组为 1 2 3 4 5， 目标n = 2
//子序列有[1, 3][1, 5][2, 4], [3, 5],共5个
//https://leetcode-cn.com/circle/discuss/dzroTG/
//原题链接如上

//#include <bits/stdc++.h>  万能头文件，并不是C++标准，也不是所有编译器都适用
//#include <iostream> 
//#include <cstdio> 
//#include <fstream> 
//#include <algorithm> 
//#include <cmath> 
//#include <deque> 
//#include <vector> 
//#include <queue> 
//#include <string> 
//#include <cstring> 
//#include <map> 
//#include <stack> 
//#include <set>

#include<iostream>
using namespace std;

typedef long long ll;
//可以直接用ll代替long long的定义,
//一般遇到数据比较大都需要用到这种定义，
//如果你在程序里不用这样的定义也可以，直接用long long定义
//，但不觉得用ll定义更方便吗，当阅读代码时，
//也能很快知道这个程序的数据很大，对了，数据多大要用long long呢？
//因为int是四个字节32位，表示的数的范围是
//-2147483648 ~ 2147483647[-2^31 ~ 2^31-1]，
const int MAXN = 20;
ll CA[MAXN] = { 1 }, CB[MAXN] = { 1 };//初始化CA和CB，CA = CB =【1 0 0 0 0 ...】
int len, n;//n表示子序列长度

signed main() //主函数由int main()改成signed main(),好处：把int改成long long 的时候不用单独把它改成int了
{
    cout << "请输入数组长度len=" << endl;
    cin >> len ;
    cout << "请输入子序列长度n=" << endl;
    cin >> n;
    //int A =3, B = 2;调试用，计算输入数组中奇数A个，偶数B个
    for (int i = 0, x; i < len; i++) { cin >> x; if (x & 1) A++; else B++; }//x & 1,x为奇数，x & 1 = 1；x为偶数，x  & 1 = 0；
    //例如输入数组x = 1 2 3 4 5
    ll ans = 0;
    for (int i = 1; i <= A; i++) 
    {
        CA[i] = CA[i - 1] * (A - i + 1) / i;//排列组合CA = [1 3 3 1 0 0 ...]，其中CA[0] = C30 = 1表示A（=3）个奇数里随机选0个有1种选择;CA[1] = C31 = 3表示A（=3）个奇数里随机选1个有3种选择,CA[2] = C32 =3,CA[3] = C33 =1
    }
    for (int i = 1; i <= B; i++) 
    {
        CB[i] = CB[i - 1] * (B - i + 1) / i;//排列组合CB = [1 2 1 0 0 ...]
    }
    for (int i = 0; i <= n; i += 2) //i表示子序列中奇数的个数0，2，...，<=n
    {
        if (n - i <= B)//n - i表示子序列中偶数的个数
        {
            ans += CA[i] * CB[n - i];
        }
    }
    cout << ans << endl;
    system("pause");
    system("cls");
    return 0;
}
/*
5 2
1 2 3 4 5
->ans=4
 */
