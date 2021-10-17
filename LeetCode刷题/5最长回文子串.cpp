//https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
//看官方视频题解，动态规划法更容易理解，时间和空间复杂度都是O（n^2），n是原字符串长度len
//还有暴力枚举所有子串，再判断是否是回文数，求出最长的，O（n^3）
//中心扩散法，时间复杂度：O(n^2)，空间复杂度：O(1)

//复杂度为 O(n)O(n) 的 \text{Manacher}Manacher 算法。然而本算法十分复杂，一般不作为面试内容。
#include<iostream>
using namespace std;
#include<vector>
#include<string>

string longestPalindrome(string& s)
{
	int len = s.size();
	if (len < 2)
	{
		return s;
	}

	int maxLen = 1;//最长回文子串长度
	int begin = 0;//最长回文子串起始位置

	vector<vector<int>>dp(len, vector<int>(len));//创建一个二维“状态”数组，大小维len*len，dp[i][j]  表示子串s[i...j]是否为回文串
    //状态转移方程  dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]，s[i...j]是否为回文串取决于两端s[i]==s[j]  和  他的去掉两端的子串是否为回文串
    //边界条件，当s[i]==s[j] ，(j-1)  - (i+1) +1 < 2, 即 j - i < 3时，子串s[i...j]的子串一定时回文串，所以子串s[i...j]也为回文串

	//初始化：所有长度为1的字符串都是回文串，即d[i][i] = 1;
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
	}

    // 递推开始
        // 先枚举子串长度
    for (int L = 2; L <= len; L++)
    {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < len; i++)
        {
            // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
            int j = L + i - 1;//右边界
            // 如果右边界越界，就可以退出当前循环
            if (j >= len) 
            {
                break;
            }

            if (s[i] != s[j]) 
            {
                dp[i][j] = false;
            }
            else //s[i] = s[j]
            {
                if (j - i < 3)
                {
                    dp[i][j] = true; //边界条件，当s[i]==s[j] ，(j-1)  - (i+1) +1 < 2, 即 j - i < 3时，子串s[i...j]的子串一定时回文串，所以子串s[i...j]也为回文串
                }
                else 
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
            if (dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}
int main()
{
    string s1 = "babad";
    cout << longestPalindrome(s1)<< endl;
	system("pause");
	system("cls");
	return 0;
}
