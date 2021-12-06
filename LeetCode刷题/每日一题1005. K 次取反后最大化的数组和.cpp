#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // ���򣬰ѿ����еĸ����ŵ�ǰ��
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // ̰�ģ�����Ǹ�������k����ӯ�࣬�ͰѸ���������
            if (nums[i] < 0 && k > 0) {
                nums[i] = -1 * nums[i];
                k--;
            }
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        // ���kûʣ����˵����ת�ĸ�����ת���ˣ��Ѿ������ͣ�����sum
        // ���k��ʣ��˵�������Ѿ�ȫ��ת�����������k��ʣż�������Լ�������������ɾ�������k��ʣ�������ͼ���2����С������
        return sum - (k % 2 == 0 ? 0 : 2 * nums[0]);
    }
};
int main() {
    vector<int> test = { 3, -1, 0, 2 };
    int res = 0;
    res = Solution().largestSumAfterKNegations(test, 3);
    cout << res << endl;//6

	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
