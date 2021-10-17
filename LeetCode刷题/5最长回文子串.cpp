//https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
//���ٷ���Ƶ��⣬��̬�滮����������⣬ʱ��Ϳռ临�Ӷȶ���O��n^2����n��ԭ�ַ�������len
//���б���ö�������Ӵ������ж��Ƿ��ǻ������������ģ�O��n^3��
//������ɢ����ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1)

//���Ӷ�Ϊ O(n)O(n) �� \text{Manacher}Manacher �㷨��Ȼ�����㷨ʮ�ָ��ӣ�һ�㲻��Ϊ�������ݡ�
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

	int maxLen = 1;//������Ӵ�����
	int begin = 0;//������Ӵ���ʼλ��

	vector<vector<int>>dp(len, vector<int>(len));//����һ����ά��״̬�����飬��Сάlen*len��dp[i][j]  ��ʾ�Ӵ�s[i...j]�Ƿ�Ϊ���Ĵ�
    //״̬ת�Ʒ���  dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]��s[i...j]�Ƿ�Ϊ���Ĵ�ȡ��������s[i]==s[j]  ��  ����ȥ�����˵��Ӵ��Ƿ�Ϊ���Ĵ�
    //�߽���������s[i]==s[j] ��(j-1)  - (i+1) +1 < 2, �� j - i < 3ʱ���Ӵ�s[i...j]���Ӵ�һ��ʱ���Ĵ��������Ӵ�s[i...j]ҲΪ���Ĵ�

	//��ʼ�������г���Ϊ1���ַ������ǻ��Ĵ�����d[i][i] = 1;
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
	}

    // ���ƿ�ʼ
        // ��ö���Ӵ�����
    for (int L = 2; L <= len; L++)
    {
        // ö����߽磬��߽���������ÿ��Կ���һЩ
        for (int i = 0; i < len; i++)
        {
            // �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
            int j = L + i - 1;//�ұ߽�
            // ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
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
                    dp[i][j] = true; //�߽���������s[i]==s[j] ��(j-1)  - (i+1) +1 < 2, �� j - i < 3ʱ���Ӵ�s[i...j]���Ӵ�һ��ʱ���Ĵ��������Ӵ�s[i...j]ҲΪ���Ĵ�
                }
                else 
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            // ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
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
