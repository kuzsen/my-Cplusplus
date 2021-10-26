
//  https://blog.csdn.net/qq_28410301/article/details/100182901  CSDN����
//  https://www.bilibili.com/video/BV13441117i4?p=2  ��Ƶ����

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isMatch(string s, string p) {
    //����һ�����ݹ���ݷ�
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

// ������  ��̬�滮����״̬ת��     dp(i,j)��ʾ��s��ǰi���ַ���p��ǰj���ַ��Ƿ�ƥ�䡣

bool first_match1(string s, string p, int i, int j) {
    return s[i] == p[j] || p[j] == '.';
}

bool isMatch1(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));//��dp���������������ӳ�ʼdp[0][0]=true��ʼ�����õ�dp[s.size()][p.szie()]Ϊֹ��
    dp[0][0] = true;//s,p��Ϊ��
    //��ʼ����1�У���sΪ�գ�p=a*b*c*
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
   
    while (true)//while�����������Զ���������ܷ���
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
