#include<iostream>
using namespace std;
void insert(int nums[], int length, int target)
{
	int i = length - 1;
	while (i >= target)
	{
		nums[i + 1] = nums[i];
		i--;
	}
	nums[target] = target;
	for (int j = 0; j < length + 1; j++)
	{
		cout << nums[j] << endl;
	}
}
int main()
{
	int nums[] = { 1,2,3,4,5,7 };
	int length = sizeof(nums) / sizeof(nums[0]);
	cout << length << endl;
	insert(nums, length, 2);
	system("pause");
	system("cls");
	return 0;
}
