#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>&intervals, vector<int>&newInterval) {
        vector<vector<int>> result;
        int index = 0; // intervals������
        // ����һ���ҵ���Ҫ�ϲ������䣬�ҵ�newInterval�����λ��index
        while (index < intervals.size() && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index++]); // ��newInterval������ߵĲ�����
        }
        // ��ʱintervals[index][1] >= newInterval[0]

        // ��������ϲ�����
        while (index < intervals.size() && newInterval[1] >= intervals[index][0]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        // ��ʱ newInterval[1] < intervals[index][0]
        result.push_back(newInterval); // ���ϲ����һ�����䣬������

        // ������������ϲ�����֮�������
        while (index < intervals.size()) {
            result.push_back(intervals[index++]); // ��ʣ�µ����������
        }
        return result;
    }
};

// ���ߣ�carlsun-2
// ���ӣ�https://leetcode-cn.com/problems/insert-interval/solution/57-cha-ru-qu-jian-mo-ni-cha-ru-xiang-jie-by-carlsu/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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
