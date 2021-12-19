#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int longestValidParentheses(string s) {
        // ��̬�滮���������ٷ����dp[i] ��ʾ���±� i �ַ���β�����Ч���ŵĳ���
        // ������⣬���ѣ��������ַ�����û��
        int resMax = 0, n = s.size();
        vector<int> dp(n, 0); // ���������,'('��Ӧ��dp��Ϊ0
        // for (int i = 0; i < n; ++i) {
        for (int i = 1; i < n; ++i) { // ��һ���ַ���dp[0]һ��Ϊ0
            if (s[i] == ')') { // ��s[i] == '(',dp[i] = 0,ֱ�������һ��
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2; // ��һ�����() 
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') { //s[i - 1] == ')' ,��Ϊs[i] Ϊ '(' �� ')'
                // �ڶ������ s[i]=s[i-1]=')',��s[i-1]��һ����Ч�����ַ��Ӵ�k�Ľ�β��k�ĳ���Ϊdp[i-z],��k����һ���ַ�c='(',����ַ����±���i - dp[i - 1] - 1������ַ���s[i]�����γ�һ����Ч���ţ������Ч���ŵ�������k
                    dp[i] = ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) +
                        // c='('��֮ǰ����Ч�Ӵ�����
                        dp[i - 1] +             // ��Ч�����ַ��Ӵ�k�ĳ���
                        2;                      // c��s�γɵ�һ�����ų���
                }
                resMax = max(resMax, dp[i]); // ����dp�����е����ֵ
            }
        }
        return resMax;
    }
};
int main()
{
    string s = "()(())";
    int res = Solution().longestValidParentheses(s);
    cout << "���Ч���ų��ȣ� " << res << endl; // 6
	system("pause");
	system("cls");
	return 0;
}
