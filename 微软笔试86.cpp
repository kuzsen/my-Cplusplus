/*#include<iostream>
#include <queue>
#include <string>
using namespace std;*/
/*
int solution(string& S, int B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    // 大顶堆
    priority_queue<int> pq;
    int N = S.size();
    for (int i = 0; i < N;) {
        if (S[i] == 'x') { // i是当前坑起点
            int j = i + 1;
            while (j < N && S[j] == 'x') {
                j++;
            }
            // j - 1是当前连续坑的尾部
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



// 科大讯飞笔试第三题，leetcode原题115，dfs会超时？
/*class Solution {
private:
    int res;
    int n;
    // string s = "iflytek";
    string s = "bag";
public:*/
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 查找"iflytek"子串
     * @param str string字符串 输入字符串
     * @return int整型
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
            if (words[i] != ' ') { // 找到一个单词word的起点
                int num = INT32_MAX; // words中可以形成当前单词word的个数
                unordered_map<char, int> curcnt;
                curcnt[words[i]]++;
                int j = i + 1;
                while (j < words.size() && words[j] != ' ') { // 注意不要上来就j++，因为j = i+ 1
                    curcnt[words[j]]++;
                    j++;
                }
                // string word = words.substr(i, j - i);
                for (unordered_map<char, int> :: iterator it = curcnt.begin(); it != curcnt.end(); it++) {
                    if (cnt.count(it->first) < 1) {
                        num = 0;
                        break;
                    }
                    // words中的字符c是当前word中c的倍数，维护其最小值 
                    num = min(cnt[it->first] / it->second, num); 
                }
                curres = max(curres, num); // 不同单词对应的num不同，对于一组case，维护其最大值
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