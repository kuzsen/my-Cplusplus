#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int longestValidParentheses(string s) {
        // 动态规划————官方题解dp[i] 表示以下标 i 字符结尾的最长有效括号的长度
        // 容易理解，不难，另外两种方法还没看
        int resMax = 0, n = s.size();
        vector<int> dp(n, 0); // 填这个数组,'('对应的dp均为0
        // for (int i = 0; i < n; ++i) {
        for (int i = 1; i < n; ++i) { // 第一个字符的dp[0]一定为0
            if (s[i] == ')') { // 若s[i] == '(',dp[i] = 0,直接求解下一个
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2; // 第一种情况() 
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') { //s[i - 1] == ')' ,因为s[i] 为 '(' 或 ')'
                // 第二种情况 s[i]=s[i-1]=')',且s[i-1]是一个有效括号字符子串k的结尾，k的长度为dp[i-z],且k的上一个字符c='(',这个字符的下标是i - dp[i - 1] - 1，这个字符与s[i]可以形成一对有效括号，这个有效括号的里面是k
                    dp[i] = ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) +
                        // c='('，之前的有效子串长度
                        dp[i - 1] +             // 有效括号字符子串k的长度
                        2;                      // c与s形成的一对括号长度
                }
                resMax = max(resMax, dp[i]); // 更新dp数组中的最大值
            }
        }
        return resMax;
    }
};
int main()
{
    string s = "()(())";
    int res = Solution().longestValidParentheses(s);
    cout << "最长有效括号长度： " << res << endl; // 6
	system("pause");
	system("cls");
	return 0;
}
