#include<iostream>
using namespace std;
#include<vector>
/*
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            //int mid = (left + right) / 2;
            int mid = (left + right) >> 1;//同上
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
    //看到升序数组想到用二分法
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);//查找第一个大于等于target的下标
        int rightIdx = binarySearch(nums, target, false) - 1;//查找第一个大于target的下标，再减去1，即为最后一个target的下标
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {//判断是否满足条件
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

/*
二分用这个模板就不会出错了。满足条件的都写l = mid或者r = mid，mid首先写成l + r >> 1，如果满足条件选择的是l = mid，那么mid那里就加个1，写成l + r + 1 >> 1。然后就是else对应的写法l = mid对应r = mid - 1，r = mid对应l = mid + 1。跟着y总学的，嘿嘿。
l + r >> 1是除以2向下取整，所以找的是左边界， l+r+1>>2是除以2向上取整，所以找的是右边界
https://www.acwing.com/blog/content/31/      二分查找算法模板
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans(2, -1);
        if (n == 0) return ans;

        int l = 0, r = n - 1;//模板一：寻找左边界
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[r] != target) return ans;
        ans[0] = r;

        l = 0, r = n - 1;//模板二：寻找右边界
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        ans[1] = r;

        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/zai-pai-xu-shu-zu-zhong-cha-zhao-yuan-su-de-di-3-4/
int main()
{

	system("pause");
	system("cls");
	return 0;
}
