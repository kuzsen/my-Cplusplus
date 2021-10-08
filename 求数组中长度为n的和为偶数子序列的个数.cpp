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
ll CA[MAXN] = { 1 }, CB[MAXN] = { 1 };
int len, n;

signed main() //主函数由int main()改成signed main(),好处：把int改成long long 的时候不用单独把它改成int了
{
    cin >> len >> n;
    int A = 0, B = 0;
    for (int i = 0, x; i < len; i++) { cin >> x; if (x & 1) A++; else B++; }

    ll ans = 0;
    for (int i = 1; i <= A; i++) {
        CA[i] = CA[i - 1] * (A - i + 1) / i;
    }
    for (int i = 1; i <= B; i++) {
        CB[i] = CB[i - 1] * (B - i + 1) / i;
    }
    for (int i = 0; i <= n; i += 2) {
        if (n - i <= B) {
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
