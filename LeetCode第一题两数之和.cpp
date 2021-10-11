#include<iostream>
#include<vector>
#include<map>//map��multimap�ĵײ�ʵ���Ǻ����
#include<unordered_map>//unordered_map�ײ�ʵ���ǹ�ϣ��Ч�ʸ���
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> a;
		unordered_map<int, int> map1;
		for (int i = 0; i <= nums.size(); i++)
		{
			if (map1.find(target - nums[i]) != map1.end())
			{
				a.push_back(map1[target - nums[i]]);
				a.push_back(i);
				return a;
				//cout << a[0] << a[1] << endl;
			}
			else
			{
				map1[nums[i]] = i;
			}
			if (i == nums.size()-1 && a.size() == 0)//��������nums�����һ��Ԫ�أ���Ȼû��ƥ�䵽��˵������nums������û������Ԫ��֮��=target��������±�0 0
			{
				a.push_back(0);
				a.push_back(0);
				//cout << "����nums������û������Ԫ��֮��=target" << endl;
				return a;
			}
		}
		return a;//return����ķ���ֵ����Ϊvector<int>����
	}
};

//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		unordered_map<int, int> map;
//		for (int i = 0; i < nums.size(); ++i)
//			if (map.find(target - nums[i]) != map.end())    return { map[target - nums[i]], i };
//			else map[nums[i]] = i;
//		return {};
//	}
//};

int main()
{
	vector<int> nums1 = { 1, 2, 3 ,4 ,4 };
	vector<int> nums2 = {};
	int target1 = 7;
	Solution test;
	test.twoSum(nums1, target1);
	nums2 = test.twoSum(nums1, target1);
	cout << nums2[0] <<" "<< nums2[1] << endl;

	system("pause");
	system("cls");
	return 0;
}

