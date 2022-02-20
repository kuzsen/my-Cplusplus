#include<iostream>
#include<queue>;
#include<unordered_map>
using namespace std;

typedef pair<char, int> P; // Ϊһ����������(�ڲ���int��char�ȣ������Զ����struct)����һ�������֣�ʹ�÷���
class Solution {
public:
    // https://leetcode-cn.com/problems/construct-string-with-repeat-limit/solution/cpython3java-1tan-xin-zui-da-dui-by-qrhq-nu2t/
    // ̰�� + ����
    // struct Cmp { //--���մ󶥶ѽ��ѡ�������������������pairĬ���Ȱ���first�Ƚ�
    //     bool operator()(const pair<int, char>& x, const pair<int, char>& y) {
    //         return x.first < y.first;
    //     }
    // };
    string repeatLimitedString(string s, int repeatLimit) {
        // �󶥶�,�洢Ԫ��pair<char, int> ��ĸcʣ��Ĵ���
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>> pq; // ����һint��ʾ��ĸa-z��1-26
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
                //-------��һ����С����ĸ(������)������һ��
                if (!pq.empty()) {
                    // auto [ch, time] = pq.top(); // Ҳ��
                    auto nextChar = pq.top();
                    pq.pop();
                    res += nextChar.first; // ƴ��һ����û������������ĸС����ĸ
                    nextChar.second--;
                    if (nextChar.second > 0) {
                        pq.emplace(nextChar.first, nextChar.second);
                    }
                    // pq.push(pair<char, int>{maxChar.first, maxChar.second}); // Ҳ��
                    // pq.push(make_pair(maxChar.first, maxChar.second)); // Ҳ��
                    pq.emplace(maxChar.first, maxChar.second); // push��Ҫ��ǰpair���죬emplace�ȹ����ٲ��룬���
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
