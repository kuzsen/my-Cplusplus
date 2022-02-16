class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/jian-zhi-56-shu-zu-zhong-shu-zi-chu-xian-rgt7/
        // ͳ��32λ�����ƣ�ÿλ��1���ֵĴ������ֱ��3ȡ��֮�󣬼�Ϊtarget�Ķ�������ʽ
        int bits[32] = { 0 }; // ��ʼ��32λ0,bit[0]��ʾ���λ1�ĸ���
        for (int i = 0; i < nums.size(); i++) {
            int j = 0;
            // ͳ��nums[i]�Ķ������и�λ�õ�1
            while (nums[i]) {
                bits[j] += (nums[i] & 1);
                nums[i] >>= 1; // ����һλ
                j++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            // ����%3 ����ö�Ӧλ������û��1 �еĻ��˶�Ӧ�� 2 ��i�η�
            res += (bits[i] % 3) * (1 << i);
        }
        return res;
    }
};