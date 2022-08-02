#include<iostream>
#include <vector>
#include <unordered_map>
// https://leetcode.cn/problems/longest-cycle-in-a-graph/
// 输入vector较大时，该方法会超时
using namespace std;
class Solution {
public:
    int longestCycle(vector<int>& e) { // e表示edges
        int n = e.size();
        vector<bool> used(n, false); // 用于标记某节点是否在一个完整环内，其余节点不必再for循环中寻找一次相同的环 
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue; // used[i],当前i已经出现在之前的环中, 跳过当前i
            // 判断以i为起点是否能形成环
            unordered_map<int, int> path;
            int d = 0;
            path[i] = 0;
            int start = i;
            while (e[start] != -1 && path.count(e[start]) == 0) { // 走到结尾或者遇到环
                d++;
                path[e[start]] = d;
                start = e[start];
            }
            if (e[start] == -1) continue; // 没有环
            if (e[start] != i) continue; // 形成的环不是以start为起点
            if (e[start] == i) { // 存在以当前i为起点的环
                res = max(res, d + 1); // 更新res
                // 以当前i为起点的环的长度，等于，该环内，以其他任一节点，为起点的环的长度，即环内其余的节点不必再从头寻找一次了，使用vector数组标记一下即可
                for (unordered_map<int, int>::iterator it = path.begin(); it != path.end(); it++) {
                    used[it->first] = true;
                }

                if (res == n) break; // 提前判断达到理论最大值，break
            }
        }
        return res;
    }
};
int main()
{
    vector<int> edges = { 1,2,0,4,5,6,3,8,9,7 };
    cout << Solution().longestCycle(edges) << endl; 

	system("pause");
	system("cls");
	return 0;
}
