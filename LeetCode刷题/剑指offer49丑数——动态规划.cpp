class Solution {
public:
    int nthUglyNumber(int n) {
        // 特殊的，1 通常被视为丑数
        // 想到动态规划，但不会实现,下一次自己做试试看
        // K神，dp[i]代表第 i + 1丑数；
        /*
        丑数的递推性质：丑数只包含因子 2, 3, 5,因此有 “丑数 == 某较小丑数× 某因子” （例如10 = =5×2）
链接：https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/
        */
        vector<int> dp(n, 0);
        dp[0] = 1; // 初始化
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5); // 第i+1个丑数是第1-i个中的一个的2/3/5倍
            // 其实就是三个指针，一开始都指向第一个位置，然后三个指针从第一个位置开始求最小值，然后最小值对应的指针往后移动，再求最小值，最小值的指针再往后移动，一直求出目标。
            if (dp[i] == n2) a++;
            if (dp[i] == n3) b++;
            if (dp[i] == n5) c++;
        }
        return dp[n - 1];
    }
};