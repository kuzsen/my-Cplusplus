#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // // ����һ������ ��1��ʼ���ң����ǲ�������ĿҪ��ʱ��/�ռ临�Ӷ�
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int j = 1;
        // for (int i = 0 ; i < n; ++i) {
        //     if (nums[i] < j) continue; // ���ų�nums������С��1������
        //     else if (nums[i] == j) j++; // ��1��ʼƥ�䵽������ƥ����һ������2
        //     else return j; // �������j����j����û�г��ֵ���С��������
        // }
        // return j; // ��������������˵��ǰ�涼ƥ��ĵ�

        // ��������ԭ�ع�ϣ��������ĿҪ��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�O(1),���ٷ���ⲻ�����
        int n = nums.size();
        for (auto& num : nums) {
            if (num <= 0) num = n + 1; // �����и������ĳ�n+1
        }
        for (int i = 0; i < n; ++i) {
            int curNum = abs(nums[i]); // ���±�i��������֮ǰ�Ѿ�����Ϊ������ʹ�þ���ֵ�ҵ�ԭ�ȵ�����
            if (curNum <= n) { // ����=����Ϊ����������Ϊ[1]ʱ
                // nums[curNum - 1] = -nums[curNum - 1]; // ����ǰ����-1=�±꣬��Ӧ�����ֱ�ɸ���
                nums[curNum - 1] = -abs(nums[curNum - 1]); // ����abs����ֵ����Ϊ����������Ϊ[1,1],���ظ�Ԫ��ʱ
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1; // ��һ��nums[i]Ϊ������˵���±�ֵi + 1���������֮ǰû�г��ֹ�
        }
        return n + 1;
    }
};
int main() {
    vector<int> nums = { 3,4,-1,1 };
    int res = Solution().firstMissingPositive(nums); // 2
    cout << "nums������ȱʧ�ĵ�һ������Ϊ�� " << res << endl;

    cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
