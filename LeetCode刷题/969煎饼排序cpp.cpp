#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> rightSort = arr;
        sort(rightSort.begin(), rightSort.end());
        vector<int> res; // �洢k
        int n = arr.size(), numBig = 0; // ��numBig+1��ֵ
        while (arr != rightSort) {
            // while (numBig <= n - 1) {
                // �ҵ����ֵ���ڵ�λ��
                // vector<int> :: iterator biggest = max_element(begin(arr), arr.end()); // ����ֵ�ǵ�����λ��
                // �������ֵ����
            int curMaxIndex = (int)(std::max_element(arr.begin(), arr.end() - numBig) - arr.begin());
            if (curMaxIndex != n - 1 - numBig) { // ��ǰ���ֵ�������ĩβ
                if (curMaxIndex != 0) {
                    // reverse(arr.begin(), arr.begin() + curMaxIndex); // �ȷŵ�ͷ��
                    reverse(arr.begin(), arr.begin() + curMaxIndex + 1); // ��תǰcurMaxIndex + 1��Ԫ��
                    // res.push_back(curMaxIndex); 
                    res.push_back(curMaxIndex + 1); // k - 1
                }
                reverse(arr.begin(), arr.end() - numBig); // �ٰѵ�ǰ���ֵ�������ĩβ
                res.push_back(n - 1 - numBig + 1);
            }
            // else continue; // ����Ѿ�����ȷλ���ϣ������
            numBig++; // ��0-��n-1-numbig����С���������ҵ�numBig+1��ֵ            
        }
        return res;
    }
};
int main()
{
    vector<int> test = { 3,2,4,1 };
    vector<int> res = Solution().pancakeSort(test);

	system("pause");
	system("cls");
	return 0;
}
