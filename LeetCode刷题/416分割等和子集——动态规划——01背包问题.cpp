#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // dp[i]中的i表示背包内总和

        // 题⽬中说：每个数组中的元素不会超过 100，数组的⼤⼩不会超过 200
        // 总和不会⼤于20000，背包最⼤只需要其中⼀半，所以10001⼤⼩就可以了
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;

        // 开始 01背包
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) { // 每⼀个元素⼀定是不可重复放⼊，所以从⼤到⼩遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]); // 第一个nums[i]是质量/重量/体积，第二个nums[i]是价值
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
        return false;
    }
};
int main()
{

	system("pause");
	system("cls");
	return 0;
}
