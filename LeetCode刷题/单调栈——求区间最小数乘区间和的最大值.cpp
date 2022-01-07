// ��������Ϊ��ҵ���CodeTop�����⣬������leetcode��84�⡪����״ͼ�����ľ��Σ����õ���ջ
/*https://mp.weixin.qq.com/s?__biz=MzkxMDMxMjY2OA==&mid=2247483766&idx=1&sn=679579e272a84efa0fe55aac4c64b5d3&chksm=c12c14c5f65b9dd383a621a79e090f6b919d9bb62cb9ff74af409d1b324d1a6188d153e8fb90&mpshare=1&scene=1&srcid=1229apmh5cbqj8W13lVuyUmF&sharer_sharetime=1640755958223&sharer_shareid=51ac78f9f13b7cad25cc120f95906bed#rd*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 500000 + 10;
int a[N];
int dp[N];
stack<int> s; // �洢������������Ԫ�ص��±�
int main()
{
    int n, res = 0;
    cin >> n; // ����1����n���鳤��,��������3
    for (int i = 0; i < n; i++) cin >> a[i]; // ����2��Ϊ���鸳ֵ���Ǹ�����������a= {6,2,1}�������resӦ��Ϊ36

    //ǰ׺�ͱ��ڿ���������ͣ����硣l��r��ȡֵ��Χ��[0,n)
    /*
        dp[1] = a[0],dp[2] = a[0] + a[1],dp[3] = a[0] + a[1] + a[2], ����dp[i]��ʾ0~i-1������Ԫ�صĺ�


        ��[l,r]�����=dp[r+1] - dp[l] -------���ͣ��������
        a[0] + a[1] + ... + a[l-1] = dp[l]
        a[0] + a[1] + ... + a[l-1] + a[l] + a[l+1] +...+ a[r-1] + a[r] = dp[r+1]
        ����dp[r+1] - dp[l] = a[l] + a[l+1] +...+ a[r-1] + a[r]
    
    */
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + a[i - 1]; 

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            int peak = a[s.top()]; // peak��������С����i���ұߵ�һ��С��peak����
            s.pop();
            int l = s.empty() ? -1 : s.top(); // ��ʱs.top()����ߵ�һ��С��peak����,��ʱ�����ж�s��Ϊ�գ�˵������ԭ��ֻ��һ��Ԫ�أ�����߲�����С��peak��Ԫ�أ�����l = -1��leetcode84�Ľ���취��������ͷ������Ԫ��0
            int r = i; // i���ұߵ�һ��С��peak����

            //l��r���������ߵ�һ��С��peak�ı߽磬��˴��ڵ���peak������[l+1,r-1]����ǰ��ǰ׺�ͷ������������dp[r]-dp[l+1]
            int sum = dp[r] - dp[l + 1];
            res = max(res, peak * sum);
        }
        s.push(i);
    }
    while (!s.empty())  // ��ֹ�����ǵ������飬�����forѭ��ֻ�ܲ���ջ�������ܵ�����leetcode84�Ľ���취��������ĩβ����Ԫ��0�����ɱ�֤���һ������������
    {
        int peak = a[s.top()];
        s.pop();
        int l = s.empty() ? -1 : s.top();
        int r = n;

        int sum = dp[r] - dp[l + 1];
        res = max(res, peak * sum);
    }

    cout << res << endl; // 36

    system("pause");
    system("cls");
    return 0;
}