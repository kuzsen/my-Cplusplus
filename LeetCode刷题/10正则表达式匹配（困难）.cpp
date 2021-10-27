
//  https://blog.csdn.net/qq_28410301/article/details/100182901  CSDN讲解
//  https://www.bilibili.com/video/BV13441117i4?p=2  视频讲解

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isMatch(string s, string p) {
    //方法一——递归回溯法
    if (p.empty()) {
        return s.empty();
    }

    bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

    if (p.size() >= 2 && p[1] == '*') {
        return bool(isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
    }
    else {
        return bool(first_match && isMatch(s.substr(1), p.substr(1)));
    }

}

//方法一优化——非常节约内存
//两个版本的算法完全一样。区别在易读版本的 substr 会创建新字符串，产生大量的内存申请和复制的操作。优化后的版本规避了此问题

class Solution {
public:
    bool isMatch3(string s, string p) {
        return isMatch3(s.c_str(), p.c_str());//c_str()就是将C++的string转化为C的字符串数组，c_str()生成一个const char *指针，指向字符串的首地址。
    }

    bool isMatch3(const char* s, const char* p) {
        if (*p == 0) return *s == 0;

        auto first_match3 = *s && (*s == *p || *p == '.');

        if (*(p + 1) == '*') {
            return isMatch3(s, p + 2) || (first_match3 && isMatch3(++s, p));
        }
        else {
            return first_match3 && isMatch3(++s, ++p);
        }
    }
};

// 方法二  动态规划法，状态转移     dp(i,j)表示：s的前i个字符和p的前j个字符是否匹配。

bool first_match1(string s, string p, int i, int j) {
    return s[i] == p[j] || p[j] == '.';
}

bool isMatch1(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));//把dp这个矩阵给填满，从初始dp[0][0]=true开始，到得到dp[s.size()][p.szie()]为止。
    dp[0][0] = true;//s,p均为空
    //初始化第1列，即s为空，p=a*b*c*
    for (int j = 2; j < p.size(); j++)
    {
        dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < p.size(); j++) {

            if (p[j] == '*') {
                dp[i + 1][j + 1] = dp[i + 1][j - 1] || first_match1(s, p, i, j - 1) && dp[i][j + 1];
            }
            else {
                dp[i + 1][j + 1] = first_match1(s, p, i, j) && dp[i][j];
            }

            cout << dp[i + 1][j + 1] << " ";
        }
        cout << endl;
    }
    return dp[s.size()][p.size()];

}

int main()
{
    string s;
    string p;
   
    while (true)//while可以连续测试多种情况，很方便
    {
        getline(cin, s);
        getline(cin, p);

        cout << isMatch(s, p) << endl;

        cout << isMatch1(s, p) << endl;
    }
	system("pause");
	system("cls");
	return 0;
}
