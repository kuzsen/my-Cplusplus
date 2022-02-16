class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/jian-zhi-56-shu-zu-zhong-shu-zi-chu-xian-rgt7/
        // 统计32位二进制，每位上1出现的次数，分别对3取余之后，即为target的二进制形式
        int bits[32] = { 0 }; // 初始化32位0,bit[0]表示最低位1的个数
        for (int i = 0; i < nums.size(); i++) {
            int j = 0;
            // 统计nums[i]的二进制中各位置的1
            while (nums[i]) {
                bits[j] += (nums[i] & 1);
                nums[i] >>= 1; // 右移一位
                j++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            // 利用%3 来求得对应位置上有没有1 有的话乘对应的 2 的i次方
            res += (bits[i] % 3) * (1 << i);
        }
        return res;
    }
};