class Solution {
public:
    int nthUglyNumber(int n) {
        // ����ģ�1 ͨ������Ϊ����
        // �뵽��̬�滮��������ʵ��,��һ���Լ������Կ�
        // K��dp[i]����� i + 1������
        /*
        �����ĵ������ʣ�����ֻ�������� 2, 3, 5,����� ������ == ĳ��С������ ĳ���ӡ� ������10 = =5��2��
���ӣ�https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/
        */
        vector<int> dp(n, 0);
        dp[0] = 1; // ��ʼ��
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5); // ��i+1�������ǵ�1-i���е�һ����2/3/5��
            // ��ʵ��������ָ�룬һ��ʼ��ָ���һ��λ�ã�Ȼ������ָ��ӵ�һ��λ�ÿ�ʼ����Сֵ��Ȼ����Сֵ��Ӧ��ָ�������ƶ���������Сֵ����Сֵ��ָ���������ƶ���һֱ���Ŀ�ꡣ
            if (dp[i] == n2) a++;
            if (dp[i] == n3) b++;
            if (dp[i] == n5) c++;
        }
        return dp[n - 1];
    }
};