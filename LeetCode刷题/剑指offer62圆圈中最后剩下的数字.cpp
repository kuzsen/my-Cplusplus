#include<iostream>
#include<vector>
using namespace std;
//class Solution { // �ᳬʱ
//public:
//    int lastRemaining(int n, int m) {
//        vector<int> nums;
//        for (int i = 0; i < n; i++) {
//            nums.push_back(i);
//        }
//        int startIndex = 0;
//        while (n > 1) {
//            int deleteNumIndex = (startIndex + (m - 1) % n) % n; // �ҵ���һ����startIndex��ʼ�ĵ�m�����֣�%n����Ϊ�����±�ѭ��
//            nums.erase(nums.begin() + deleteNumIndex); // ɾ���±�ΪdeleteNumIndex��Ԫ��
//            n--; // ɾ�������鳤�ȼ�һ
//            // startIndex = (deleteNumIndex + 1) % n; // ɾ�������һ�����ֿ�ʼ����
//            startIndex = deleteNumIndex % n; // ��Ϊɾ��λ�õ�Ԫ���Ѿ���ɾ����ɾ��λ�ú����Ԫ�ض�ǰ���ˡ���ɾ�����ñ�ɾ���ε���һ��Ԫ�ش����ˡ�
//        }
//        return nums[n - 1]; // ��ʱn=1
//    }
//};

class Solution { 
public:
    int lastRemaining(int n, int m) {
        // Լɪ�򻷣���ǿ��⡪������������������ֻ�������ջ����Ǹ��˵����F(n,m)�仯
        //  https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/

        int pos = 0; // ���ջ������Ǹ��˵ĳ�ʼλ�ã�F(1, m) = 0
        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i;  // ÿ��ѭ������,���pos��F(i,m),�ұ�pos��F(i-1,m),��ǰ��i��Ԫ��
        }
        return pos;
    }
};
int main()
{
    int res = Solution().lastRemaining(71989, 111059); // leetcode�ϻᳬʱ����֤���res = 
    cout << res << endl; // 34203
	system("pause");
	system("cls");
	return 0;
}
