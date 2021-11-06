//https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode-solution/
//双指针法，移动较短边指针
#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
		int temp = min(height[l], height[r]) * (r - l);//自动对其ctrl+k+F
		ans = max(ans, temp);
		if (height[l] <= height[r])
        {
           l++;
        } 
        else
        { 
          r--;
        }

    }
    return ans;
}
int main()
{
    vector<int> hegiht = { 1,8,6,2,5,4,8,3,7 };
    int res = 0;
    res = maxArea(hegiht);
    //vector<int> hegiht = { 1,4,3,4 };

    cout << maxArea(hegiht) << endl;

	system("pause");
	system("cls");
	return 0;
}
