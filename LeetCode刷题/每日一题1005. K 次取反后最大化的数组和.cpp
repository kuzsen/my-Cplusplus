#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 排序，把可能有的负数排到前面
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 贪心：如果是负数，而k还有盈余，就把负数反过来
            if (nums[i] < 0 && k > 0) {
                nums[i] = -1 * nums[i];
                k--;
            }
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        // 如果k没剩，那说明能转的负数都转正了，已经是最大和，返回sum
        // 如果k有剩，说明负数已经全部转正，所以如果k还剩偶数个就自己抵消掉，不用删减，如果k还剩奇数个就减掉2倍最小正数。
        return sum - (k % 2 == 0 ? 0 : 2 * nums[0]);
    }
};
int main() {
    vector<int> test = { 3, -1, 0, 2 };
    int res = 0;
    res = Solution().largestSumAfterKNegations(test, 3);
    cout << res << endl;//6

	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
