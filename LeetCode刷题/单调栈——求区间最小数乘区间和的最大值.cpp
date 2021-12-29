// 本题链接为企业题库CodeTop面试题，类似于leetcode第84题——柱状图中最大的矩形，利用单调栈
/*https://mp.weixin.qq.com/s?__biz=MzkxMDMxMjY2OA==&mid=2247483766&idx=1&sn=679579e272a84efa0fe55aac4c64b5d3&chksm=c12c14c5f65b9dd383a621a79e090f6b919d9bb62cb9ff74af409d1b324d1a6188d153e8fb90&mpshare=1&scene=1&srcid=1229apmh5cbqj8W13lVuyUmF&sharer_sharetime=1640755958223&sharer_shareid=51ac78f9f13b7cad25cc120f95906bed#rd*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 500000 + 10;
int a[N];
int dp[N];
stack<int> s; // 存储单调递增数组元素的下标
int main()
{
    int n, res = 0;
    cin >> n; // 条件1——n数组长度,例如输入3
    for (int i = 0; i < n; i++) cin >> a[i]; // 条件2：为数组赋值（非负数），例如a= {6,2,1}，则输出res应当为36

    //前缀和便于快速求区间和，例如。l和r的取值范围是[0,n)
    /*
        dp[1] = a[0],dp[2] = a[0] + a[1],dp[3] = a[0] + a[1] + a[2], 所以dp[i]表示0~i-1个数组元素的和


        求[l,r]区间和=dp[r+1] - dp[l] -------解释，容易理解
        a[0] + a[1] + ... + a[l-1] = dp[l]
        a[0] + a[1] + ... + a[l-1] + a[l] + a[l+1] +...+ a[r-1] + a[r] = dp[r+1]
        所以dp[r+1] - dp[l] = a[l] + a[l+1] +...+ a[r-1] + a[r]
    
    */
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + a[i - 1]; 

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            int peak = a[s.top()]; // peak是区间最小数，i是右边第一个小于peak的数
            s.pop();
            int l = s.empty() ? -1 : s.top(); // 此时s.top()是左边第一个小于peak的数,此时加入判断s，为空，说明里面原来只有一个元素，即左边不存在小于peak的元素，设置l = -1，leetcode84的解决办法是在数组头部插入元素0
            int r = i; // i是右边第一个小于peak的数

            //l和r是左右两边第一个小于peak的边界，因此大于等于peak区间是[l+1,r-1]，经前面前缀和分析，其区间和dp[r]-dp[l+1]
            int sum = dp[r] - dp[l + 1];
            res = max(res, peak * sum);
        }
        s.push(i);
    }
    while (!s.empty())  // 防止数组是递增数组，上面的for循环只能插入栈、而不能弹出，leetcode84的解决办法是在数组末尾插入元素0，即可保证最后一定可以输出面积
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