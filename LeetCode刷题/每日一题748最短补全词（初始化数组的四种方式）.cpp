#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ���ߣ�LeetCode-Solution
// ���ӣ�https://leetcode-cn.com/problems/shortest-completing-word/solution/zui-duan-bu-quan-ci-by-leetcode-solution-35pt/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //��¼licensePlate��26����ĸ�ĸ���
        //**************************************�����ǳ�ʼ�������4�ַ�ʽ
        //int cnt[26] = {0};
        int cnt[26]{};
        //vector<int> cnt(26, 0);
        //array<int, 26> cnt{};
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ++cnt[tolower(ch) - 'a'];
            }
        }
        int idx = -1;
        for (int i = 0; i < words.size(); ++i) {
            array<int, 26> c{};
            for (char ch : words[i]) {
                ++c[ch - 'a'];
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (c[j] < cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (idx < 0 || words[i].length() < words[idx].length())) {
                idx = i;
            }
        }
        return words[idx];
    }
};

class Solution2 {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cnt[26]{};
        for (char c : licensePlate) if (isalpha(c)) ++cnt[tolower(c) - 'a'];
        //stable_sort      *******   http://c.biancheng.net/view/7460.html
        //��ָ����Χ�ڰ��������ȵ�Ԫ��ʱ��sort() �������޷���֤���ı����ǵ����λ�á���ô�������Ҫ���������Ҫ��֤���Ԫ�ص����λ�ã�����ô���أ�����ʹ�� stable_sort() ������
        //lambda���ʽ      ******    https://segmentfault.com/a/1190000040031948
        stable_sort(begin(words), end(words), [](auto&& a, auto&& b) {return a.size() < b.size(); });
        for (auto&& s : words) {
            int cnt2[26]{}, flag = true;
            for (char c : s)if (isalpha(c)) ++cnt2[tolower(c) - 'a'];
            for (int i = 0; i < 26; ++i) if (cnt2[i] < cnt[i]) { flag = false; break; }
            if (flag) return s;
        }
        return "";
    }
};

int main()
{

	system("pause");
	system("cls");
	return 0;
}
