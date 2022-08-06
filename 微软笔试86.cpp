#include<iostream>
#include <queue>
#include <string>
using namespace std;
/*
int solution(string& S, int B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    // �󶥶�
    priority_queue<int> pq;
    int N = S.size();
    for (int i = 0; i < N;) {
        if (S[i] == 'x') { // i�ǵ�ǰ�����
            int j = i + 1;
            while (j < N && S[j] == 'x') {
                j++;
            }
            // j - 1�ǵ�ǰ�����ӵ�β��
            pq.push(j - i);
            i = j;
        }
        else i++;
    }
    int res = 0;
    while (!pq.empty() && B > 0) {
        int maxLen = pq.top();
        if (maxLen + 1 <= B) {
            res += maxLen;
            B -= (maxLen + 1);
        }
        else {
            res += (B - 1);
            B = 0;
        }
        pq.pop();
    }
    return res;
}
int main()
{
    // string s = "...xxx..x....xxx";
    string s = ".xxxxx";
    int b = 5;
    int r = solution(s, b);
    cout << r;
	system("pause");
	system("cls");
	return 0;
}
*/
class Solution {
private:
    int res;
    int n;
    string s = "iflytek";
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����"iflytek"�Ӵ�
     * @param str string�ַ��� �����ַ���
     * @return int����
     */
    void dfs(string& str, int start, int ind) {
        if (ind == 7) {
            res++;
            return;
        }
        for (int i = start; i < n; i++) {
            if (str[i] == s[ind]) {
                dfs(str, i + 1, ind + 1);
            }
        }
    }
    int findIflytek(string str) {
        // write code here
        n = str.size();
        dfs(str, 0, 0);
        return res;
    }
};

int main() {

    string str = "iflylytfetkeefek";
    cout << Solution().findIflytek(str);

    system("pause");
    system("cls");
    return 0;
}