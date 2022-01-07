#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
// �Զ���ıȽϺ���
// bool compare(vector<int> interval_1, const vector<int> interval_2) {
//     return interval_1[0] < interval_2[0];
// }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // �ٷ����
        // ���򣬽��б��е����䰴����˵���������
        sort(intervals.begin(), intervals.end()); // Ĭ����������
        // �Զ���ıȽϺ�����һ��Ҫд��ȫ�ֺ�������Ҫд�����Ա����
        // sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0], R = intervals[i][1];
            // ����һ��������� merged ������ || ��ǰ������merged���һ�����䲻�غ�
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
    // ����+˫ָ��
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());// Ĭ�ϰ��յ�һ��Ԫ����������
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) { // ���������֮������һ��i��ֵ��ѭ�����о�����������i++
            int R = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= R) {
                R = max(R, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], R });
            i = j; // ������һ�α�����i
        }
        return ans;
    }
};

// ���ߣ�ikaruga
// ���ӣ�https://leetcode-cn.com/problems/merge-intervals/solution/merge-intervals-by-ikaruga/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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
