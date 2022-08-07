/*#include<iostream>
#include <queue>
#include <string>
using namespace std;*/
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



// �ƴ�Ѷ�ɱ��Ե����⣬leetcodeԭ��115��dfs�ᳬʱ��
/*class Solution {
private:
    int res;
    int n;
    // string s = "iflytek";
    string s = "bag";
public:*/
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����"iflytek"�Ӵ�
     * @param str string�ַ��� �����ַ���
     * @return int����
     */
  /*  void dfs(string& str, int start, int ind) {
        if (ind == 3) {
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

    // string str = "iflylytfetkeefek";
    string str = "babgbag";
    cout << Solution().findIflytek(str);

    system("pause");
    system("cls");
    return 0;
}
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    //int M;
    // cin >> M;
    //vector<int> res;
    //while (M) {

       // M--;
        string S = "bbbooyy";
        // int N;
        // cin >> S;
        // cin >> N;
        string words = "bob boy" ;
        // getchar(); // https://blog.csdn.net/yrk0556/article/details/88040954
        // getline(cin, words);
        unordered_map<char, int> cnt;
        for (char c : S) {
            cnt[c]++;
        }
        int curres = 0;
        for (int i = 0; i < words.size();) {
            if (words[i] != ' ') { // �ҵ�һ������word�����
                int num = INT32_MAX; // words�п����γɵ�ǰ����word�ĸ���
                unordered_map<char, int> curcnt;
                curcnt[words[i]]++;
                int j = i + 1;
                while (j < words.size() && words[j] != ' ') { // ע�ⲻҪ������j++����Ϊj = i+ 1
                    curcnt[words[j]]++;
                    j++;
                }
                // string word = words.substr(i, j - i);
                for (unordered_map<char, int> :: iterator it = curcnt.begin(); it != curcnt.end(); it++) {
                    if (cnt.count(it->first) < 1) {
                        num = 0;
                        break;
                    }
                    // words�е��ַ�c�ǵ�ǰword��c�ı�����ά������Сֵ 
                    num = min(cnt[it->first] / it->second, num); 
                }
                curres = max(curres, num); // ��ͬ���ʶ�Ӧ��num��ͬ������һ��case��ά�������ֵ
                i = j;
            }
            else i++;
        }
        cout << curres;
        // res.push_back(curres);
    // }
    /*for (int r : res) {
        cout << r << endl;
    }*/
    system("pause");
    system("cls");
    return 0;
}