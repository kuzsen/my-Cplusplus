//����һ�����飬Ȼ���������Ϊn�ĺ�Ϊż�������и�����
//����˵����Ϊ 1 2 3 4 5�� Ŀ��n = 2
//��������[1, 3][1, 5][2, 4], [3, 5],��5��
//https://leetcode-cn.com/circle/discuss/dzroTG/
//ԭ����������

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
ll CA[MAXN] = { 1 }, CB[MAXN] = { 1 };//��ʼ��CA��CB��CA = CB =��1 0 0 0 0 ...��
int len, n;//n��ʾ�����г���

signed main() //��������int main()�ĳ�signed main(),�ô�����int�ĳ�long long ��ʱ���õ��������ĳ�int��
{
    cout << "���������鳤��len=" << endl;
    cin >> len ;
    cout << "�����������г���n=" << endl;
    cin >> n;
    //int A =3, B = 2;�����ã�������������������A����ż��B��
    for (int i = 0, x; i < len; i++) { cin >> x; if (x & 1) A++; else B++; }//x & 1,xΪ������x & 1 = 1��xΪż����x  & 1 = 0��
    //������������x = 1 2 3 4 5
    ll ans = 0;
    for (int i = 1; i <= A; i++) 
    {
        CA[i] = CA[i - 1] * (A - i + 1) / i;//�������CA = [1 3 3 1 0 0 ...]������CA[0] = C30 = 1��ʾA��=3�������������ѡ0����1��ѡ��;CA[1] = C31 = 3��ʾA��=3�������������ѡ1����3��ѡ��,CA[2] = C32 =3,CA[3] = C33 =1
    }
    for (int i = 1; i <= B; i++) 
    {
        CB[i] = CB[i - 1] * (B - i + 1) / i;//�������CB = [1 2 1 0 0 ...]
    }
    for (int i = 0; i <= n; i += 2) //i��ʾ�������������ĸ���0��2��...��<=n
    {
        if (n - i <= B)//n - i��ʾ��������ż���ĸ���
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
