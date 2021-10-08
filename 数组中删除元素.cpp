#include<iostream>
using namespace std;
void del(int nums[], int length, int target)
{
	int i = target;
	while (i < length)
	{
		nums[i] = nums[i + 1];
		i++;
	}
}
int main()
{
	int nums[] = { 1,2,3,4,5,6 };
	int target = 2;
	int length = sizeof(nums) / sizeof(nums[0]);
	del(nums, length, target);
	cout << nums[2] << endl;
	for (int j = 0; j < length-1;j++)
	{
		cout << nums[j] << endl;
	}
	system("pause");
	system("cls");
	return 0;
}
