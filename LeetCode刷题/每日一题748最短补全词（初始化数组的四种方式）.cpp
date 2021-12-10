#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/shortest-completing-word/solution/zui-duan-bu-quan-ci-by-leetcode-solution-35pt/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //记录licensePlate中26个字母的个数
        //**************************************以下是初始化数组的4种方式
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
        //当指定范围内包含多个相等的元素时，sort() 排序函数无法保证不改变它们的相对位置。那么，如果既要完成排序又要保证相等元素的相对位置，该怎么办呢？可以使用 stable_sort() 函数。
        //lambda表达式      ******    https://segmentfault.com/a/1190000040031948
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
