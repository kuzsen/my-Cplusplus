#include<iostream>
#include<queue>;
#include<unordered_map>
using namespace std;

typedef pair<char, int> P; // 为一种数据类型(内部的int，char等，还有自定义的struct)定义一个新名字，使用方便
class Solution {
public:
    // https://leetcode-cn.com/problems/construct-string-with-repeat-limit/solution/cpython3java-1tan-xin-zui-da-dui-by-qrhq-nu2t/
    // 贪心 + 最大堆
    // struct Cmp { //--按照大顶堆建堆——————————pair默认先按照first比较
    //     bool operator()(const pair<int, char>& x, const pair<int, char>& y) {
    //         return x.first < y.first;
    //     }
    // };
    string repeatLimitedString(string s, int repeatLimit) {
        // 大顶堆,存储元素pair<char, int> 字母c剩余的次数
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>> pq; // 参数一int表示字母a-z，1-26
        // for (auto [c, time] : cnt) {
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            pq.emplace(iter->first, iter->second);
        }
        string res = "";
        while (!pq.empty()) {
            auto maxChar = pq.top();
            pq.pop();

            if (maxChar.second <= repeatLimit) {
                // res += (maxChar.first + '0') * maxChar.second;
                for (int i = 0; i < maxChar.second; i++) {
                    res += maxChar.first;
                }
            }
            else { // maxChar[1] > repeatLimit
                // res += (maxChar.first + '0') * repeatLimit;
                for (int i = 0; i < repeatLimit; i++) {
                    res += maxChar.first;
                }
                maxChar.second -= repeatLimit;
                //-------放一个次小的字母(若存在)，隔断一下
                if (!pq.empty()) {
                    // auto [ch, time] = pq.top(); // 也可
                    auto nextChar = pq.top();
                    pq.pop();
                    res += nextChar.first; // 拼接一个比没有用完的最大字母小的字母
                    nextChar.second--;
                    if (nextChar.second > 0) {
                        pq.emplace(nextChar.first, nextChar.second);
                    }
                    // pq.push(pair<char, int>{maxChar.first, maxChar.second}); // 也可
                    // pq.push(make_pair(maxChar.first, maxChar.second)); // 也可
                    pq.emplace(maxChar.first, maxChar.second); // push需要提前pair构造，emplace先构造再插入，简便
                }
            }
        }
        return res;
    }
};
int main()
{
    string s = "cczazcc";
    int repeatLimit = 3;
    string res = Solution().repeatLimitedString(s, repeatLimit);
	system("pause");
	system("cls");
	return 0;
}
