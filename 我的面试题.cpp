#include <iostream>
using namespace std;
#include <vector>
void quick(vector<int>& nums, int l, int r) {
	if (l > r) return;
	int i = l, j = r, piv = nums[l];
	while (i < j) {
		while (i < j && nums[j] <= piv)
		{
			j--;
		}
		nums[i] = nums[j];
		while (i < j && nums[i] >= piv) {
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = piv; // ¸üĞÂÉÚ±øÎ»ÖÃ
	quick(nums, l, i - 1);
	quick(nums, i + 1, r);
}

vector<int> quickSort(vector<int> nums) {
	quick(nums, 0, nums.size() - 1);
	return nums;
}
int main()
{
	vector<int> nums = { 2,5,4,8,1,2 };
	vector<int> res = quickSort(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	system("pause");
	system("cls");
	return 0;
}
