#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // 思路：贪心，由于我们要求字符串尽可能地长，所以尽可能选择数量多的字符。
        string res;
        vector<pair<int, char>> cnt = { {a, 'a'}, {b, 'b'}, {c, 'c'} };

        // 逐个选择字符
        while (1) {
            // 每次选择都要重新按照剩余字符个数从大到小排序,从剩余最多的字符开始判断本轮选择
            sort(cnt.begin(), cnt.end(), [](const auto& p1, const pair<int, char>& p2) {
                return p1.first > p2.first;
                });

            bool flag = false; // 设置本轮是否选择某字符，后续判断是否仍为false，如果是，说明本轮未选择任一字符，res已经达到最长
            // 遍历不同种字符（若存在）
            for (pair<int, char>& cn : cnt) { // 当前字符ch剩余的个数num
                int n = res.size();
                if (cn.first <= 0) continue; // 字符ch已经没有剩余了
                // 如果加上当前字符ch，已经出现连续三个字符相同，则判断选择下一个字符
                if (n >= 2 && res[n - 1] == cn.second && res[n - 2] == cn.second) continue; // 比较当前字符与res倒数两个字符是否相等
                res.push_back(cn.second); // 至此，选择当前字符，剩余字符的数量就需要重新排序了，退出for循环，break
                flag = true; // 本轮选择字符ch
                cn.first--; // 当前字符ch的数量减一，引用方式传递num     
                break;
            }

            if (flag == false) break;
        }
        return res;
    }
};
int main()
{
    string test = Solution().longestDiverseString(1, 1, 7);
    cout << test << endl;
	system("pause");
	system("cls");
	return 0;
}
