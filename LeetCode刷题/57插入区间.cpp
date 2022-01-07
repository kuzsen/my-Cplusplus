#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>&intervals, vector<int>&newInterval) {
        vector<vector<int>> result;
        int index = 0; // intervals的索引
        // 步骤一：找到需要合并的区间，找到newInterval插入的位置index
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index++]); // 将newInterval区间左边的插入结果
        }
        // 此时intervals[index][1] >= newInterval[0]

        // 步骤二：合并区间
        while (index < intervals.size() && newInterval[1] >= intervals[index][0]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        // 此时 newInterval[1] < intervals[index][0]
        result.push_back(newInterval); // 将合并后的一段区间，插入结果

        // 步骤三：处理合并区间之后的区间
        while (index < intervals.size()) {
            result.push_back(intervals[index++]); // 将剩下的区间插入结果
        }
        return result;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/insert-interval/solution/57-cha-ru-qu-jian-mo-ni-cha-ru-xiang-jie-by-carlsu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main()
{
    vector<vector<int>> test = { {1,3},{6,9} };
    vector<int> newInterval = { 2,5 };
    vector<vector<int>> result = Solution().insert(test, newInterval);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << "," << result[i][1] << endl;
    }
	system("pause");
	system("cls");
	return 0;
}
