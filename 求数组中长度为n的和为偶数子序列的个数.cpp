//#include <bits/stdc++.h>  ����ͷ�ļ���������C++��׼��Ҳ�������б�����������
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
//����ֱ����ll����long long�Ķ���,
//һ���������ݱȽϴ���Ҫ�õ����ֶ��壬
//������ڳ����ﲻ�������Ķ���Ҳ���ԣ�ֱ����long long����
//������������ll����������𣬵��Ķ�����ʱ��
//Ҳ�ܺܿ�֪�������������ݺܴ󣬶��ˣ����ݶ��Ҫ��long long�أ�
//��Ϊint���ĸ��ֽ�32λ����ʾ�����ķ�Χ��
//-2147483648 ~ 2147483647[-2^31 ~ 2^31-1]��
const int MAXN = 20;
ll CA[MAXN] = { 1 }, CB[MAXN] = { 1 };
int len, n;

signed main() //��������int main()�ĳ�signed main(),�ô�����int�ĳ�long long ��ʱ���õ��������ĳ�int��
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
