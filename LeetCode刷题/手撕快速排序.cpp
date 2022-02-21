#include<iostream>
using namespace std;
#include<vector>
class mysort {
public:
	void quickSort(vector<int> &nums, int l, int r) { // l为数组起始下标，r为nums数组长度
		if (l >= r - 1) return;
		int left = l, right = r - 1;
		int piv = nums[left]; // 设置哨兵
		while (left < right) {
			while (left < right && nums[right] >= piv) right--; // 右指针，从右往左扫描，
			nums[left] = nums[right]; // 将小于piv的放到左边

			while (left < right && nums[left] <= piv) left++;
			nums[right] = nums[left];
		}
		// 更新哨兵
		nums[left] = piv;
		// 分别递归哨兵左边和右边
		quickSort(nums, l, left);
		quickSort(nums, left + 1, r);
	}
};
int main()
{
	// int a[] = { 0,34,66,2,5,95,4,46,27 };
	vector<int> a = { 0,34,66,2,5,95,4,46,27 };
	// mysort().quickSort(a, 0, sizeof(a) / sizeof(int));
	mysort().quickSort(a, 0, a.size());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " "; // print => 0 2 4 5 27 34 46 66 95
	}

	system("pause");
	system("cls");
	return 0;
}
