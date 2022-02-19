#include<iostream>
#include<vector>
using namespace std;
//class Solution { // 会超时
//public:
//    int lastRemaining(int n, int m) {
//        vector<int> nums;
//        for (int i = 0; i < n; i++) {
//            nums.push_back(i);
//        }
//        int startIndex = 0;
//        while (n > 1) {
//            int deleteNumIndex = (startIndex + (m - 1) % n) % n; // 找到下一个从startIndex开始的第m个数字，%n是因为数组下标循环
//            nums.erase(nums.begin() + deleteNumIndex); // 删除下标为deleteNumIndex的元素
//            n--; // 删除后数组长度减一
//            // startIndex = (deleteNumIndex + 1) % n; // 删除后从下一个数字开始计数
//            startIndex = deleteNumIndex % n; // 因为删除位置的元素已经被删除，删除位置后面的元素都前移了。被删除段用被删除段的下一个元素代替了。
//        }
//        return nums[n - 1]; // 此时n=1
//    }
//};

class Solution { 
public:
    int lastRemaining(int n, int m) {
        // 约瑟夫环，最强题解——————————只关心最终活着那个人的序号F(n,m)变化
        //  https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/

        int pos = 0; // 最终活下来那个人的初始位置，F(1, m) = 0
        for (int i = 2; i <= n; i++) {
            pos = (pos + m) % i;  // 每次循环右移,左边pos是F(i,m),右边pos是F(i-1,m),当前有i个元素
        }
        return pos;
    }
};
int main()
{
    int res = Solution().lastRemaining(71989, 111059); // leetcode上会超时，验证结果res = 
    cout << res << endl; // 34203
	system("pause");
	system("cls");
	return 0;
}
