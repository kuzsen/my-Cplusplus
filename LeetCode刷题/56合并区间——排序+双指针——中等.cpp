#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
// 自定义的比较函数
// bool compare(vector<int> interval_1, const vector<int> interval_2) {
//     return interval_1[0] < interval_2[0];
// }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 官方题解
        // 排序，将列表中的区间按照左端点升序排序
        sort(intervals.begin(), intervals.end()); // 默认升序排列
        // 自定义的比较函数，一定要写成全局函数，不要写成类成员函数
        // sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0], R = intervals[i][1];
            // 将第一个区间加入 merged 数组中 || 当前区间与merged最后一个区间不重合
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({ L, R });
            }
            else { // merged.back()[1] >= L
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

class Solution1 {
public:
    // 排序+双指针
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());// 默认按照第一个元素升序排列
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) { // 此题解巧妙之处，下一次i的值在循环体中决定，而不是i++
            int R = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= R) {
                R = max(R, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], R });
            i = j; // 更新下一次遍历的i
        }
        return ans;
    }
};

// 作者：ikaruga
// 链接：https://leetcode-cn.com/problems/merge-intervals/solution/merge-intervals-by-ikaruga/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main()
{
    vector<vector<int>> test = {{1,3},{2,6},{8,10},{15,18} };
    //vector<vector<int>> result = Solution().merge(test);
    vector<vector<int>> result = Solution1().merge(test);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "," << result[i][1] << endl;
    }
	system("pause");
	system("cls");
	return 0;
}
