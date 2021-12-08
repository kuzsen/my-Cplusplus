#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //���ٷ�����������
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxTotal = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3 - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx = i - k * 3 + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12Idx1 = maxSum1Idx;
                    maxSum12Idx2 = i - k * 2 + 1;
                }
                if (maxSum12 + sum3 > maxTotal) {
                    maxTotal = maxSum12 + sum3;
                    ans = { maxSum12Idx1, maxSum12Idx2, i - k + 1 };
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};

// ���ߣ�LeetCode-Solution
// ���ӣ�https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solution/san-ge-wu-zhong-die-zi-shu-zu-de-zui-da-4a8lb/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
int main()
{
    vector<int> test = { 1,2,1,2,6,7,5,1 };
    int k = 2;
    /*
        ������ [1, 2], [2, 6], [7, 5]����3������Ϊk=2�������飬֮����󣬶�Ӧ����ʼ�±�Ϊ [0, 3, 5]��
Ҳ����ȡ [2, 1], ���ǽ�� [1, 3, 5] ���ֵ����ϸ���
    */
    vector<int> res = Solution().maxSumOfThreeSubarrays(test, k);
    for (auto c : res) {
        cout << c << ' ';
    }
	system("pause");
	system("cls");
	return 0;
}
