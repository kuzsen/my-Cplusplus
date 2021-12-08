#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //看官方题解容易理解
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

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solution/san-ge-wu-zhong-die-zi-shu-zu-de-zui-da-4a8lb/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main()
{
    vector<int> test = { 1,2,1,2,6,7,5,1 };
    int k = 2;
    /*
        子数组 [1, 2], [2, 6], [7, 5]，这3个长度为k=2的子数组，之和最大，对应的起始下标为 [0, 3, 5]。
也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
    */
    vector<int> res = Solution().maxSumOfThreeSubarrays(test, k);
    for (auto c : res) {
        cout << c << ' ';
    }
	system("pause");
	system("cls");
	return 0;
}
