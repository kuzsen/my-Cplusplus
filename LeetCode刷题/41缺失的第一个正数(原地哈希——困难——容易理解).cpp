#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // // 方法一：排序 从1开始查找，但是不满足题目要求时间/空间复杂度
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int j = 1;
        // for (int i = 0 ; i < n; ++i) {
        //     if (nums[i] < j) continue; // 先排除nums数组中小于1的数字
        //     else if (nums[i] == j) j++; // 从1开始匹配到，接着匹配下一个数字2
        //     else return j; // 如果大于j，则j就是没有出现的最小的正整数
        // }
        // return j; // 数组遍历完结束，说明前面都匹配的到

        // 方法二：原地哈希，满足题目要求，时间复杂度为 O(n)，空间复杂度O(1),看官方题解不难理解
        int n = nums.size();
        for (auto& num : nums) {
            if (num <= 0) num = n + 1; // 将所有负数，改成n+1
        }
        for (int i = 0; i < n; ++i) {
            int curNum = abs(nums[i]); // 若下标i的数字在之前已经被置为负数，使用绝对值找到原先的正数
            if (curNum <= n) { // 加上=是因为，测试用例为[1]时
                // nums[curNum - 1] = -nums[curNum - 1]; // 将当前数字-1=下标，对应的数字变成负数
                nums[curNum - 1] = -abs(nums[curNum - 1]); // 加上abs绝对值是因为，测试用例为[1,1],有重复元素时
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1; // 第一个nums[i]为正数，说明下标值i + 1这个正整数之前没有出现过
        }
        return n + 1;
    }
};
int main() {
    vector<int> nums = { 3,4,-1,1 };
    int res = Solution().firstMissingPositive(nums); // 2
    cout << "nums数组中缺失的第一个正数为： " << res << endl;

    cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
