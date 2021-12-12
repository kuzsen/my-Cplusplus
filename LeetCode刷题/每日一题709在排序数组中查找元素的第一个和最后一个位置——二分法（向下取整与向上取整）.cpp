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
            int mid = (left + right) >> 1;//ͬ��
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
    //�������������뵽�ö��ַ�
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);//���ҵ�һ�����ڵ���target���±�
        int rightIdx = binarySearch(nums, target, false) - 1;//���ҵ�һ������target���±꣬�ټ�ȥ1����Ϊ���һ��target���±�
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {//�ж��Ƿ���������
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

/*
���������ģ��Ͳ�������ˡ����������Ķ�дl = mid����r = mid��mid����д��l + r >> 1�������������ѡ�����l = mid����ômid����ͼӸ�1��д��l + r + 1 >> 1��Ȼ�����else��Ӧ��д��l = mid��Ӧr = mid - 1��r = mid��Ӧl = mid + 1������y��ѧ�ģ��ٺ١�
l + r >> 1�ǳ���2����ȡ���������ҵ�����߽磬 l+r+1>>2�ǳ���2����ȡ���������ҵ����ұ߽�
https://www.acwing.com/blog/content/31/      ���ֲ����㷨ģ��
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> ans(2, -1);
        if (n == 0) return ans;

        int l = 0, r = n - 1;//ģ��һ��Ѱ����߽�
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[r] != target) return ans;
        ans[0] = r;

        l = 0, r = n - 1;//ģ�����Ѱ���ұ߽�
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        ans[1] = r;

        return ans;
    }
};

// ���ߣ�LeetCode-Solution
// ���ӣ�https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/zai-pai-xu-shu-zu-zhong-cha-zhao-yuan-su-de-di-3-4/
int main()
{

	system("pause");
	system("cls");
	return 0;
}
