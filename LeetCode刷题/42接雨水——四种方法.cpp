class Solution {
public:
    int trap(vector<int>& height) {
        // // 暴力遍历，同时找到heigth[i]左右两边的最大heigth，则heigth[i]能接min(l_max,r_max)- height[i]个格子雨水
        // int n = height.size();
        // int res = 0;
        // for (int i = 1; i < n - 1; ++i) { // 左右边界不考虑，
        //     int l_max = 0, r_max = 0;
        //     for (int j = i; j >= 0; j--) { // j = i 开始表示height[i]也参与最大值的比较
        //         l_max = max(l_max, height[j]);
        //     }
        //     for (int j = i; j < n; j++) {
        //         r_max = max(r_max, height[j]);
        //     }
        //     // if(l_max > height[i] && r_max > height[i]) { // 省去这次判断，直接将height[i]的值加入到求左右两边最大值的过程
        //     //     res += (min(l_max, r_max) - height[i]);
        //     // }
        //     res += min(l_max, r_max) - height[i];
        // }
        // return res;

        // // 官方题解：动态规划，O（n）时间求出每个位置左边、右边的最大值，用O（n）空间数组将其存储
        // int n = height.size();
        // if (n == 0) {
        //     return 0;
        // }
        // vector<int> leftMax(n);
        // leftMax[0] = height[0];
        // for (int i = 1; i < n; ++i) {
        //     leftMax[i] = max(leftMax[i - 1], height[i]);
        // }

        // vector<int> rightMax(n);
        // rightMax[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; --i) {
        //     rightMax[i] = max(rightMax[i + 1], height[i]);
        // }

        // int ans = 0;
        // for (int i = 0; i < n; ++i) {
        //     ans += min(leftMax[i], rightMax[i]) - height[i];
        // }
        // return ans;

        // 方法三：单调栈——官方题解——不难理解，遍历height数组O（n）时间，单调栈空间O(N)复杂度
        // int ans = 0;
        // stack<int> stk;  // 栈底到栈底下标对应的元素值递减
        // int n = height.size();
        // for (int i = 0; i < n; ++i) {
        //     while (!stk.empty() && height[i] > height[stk.top()]) { // i其实就是右边第一个大于top的
        //         int top = stk.top();
        //         stk.pop();
        //         if (stk.empty()) {
        //             break;
        //         }
        //         int left = stk.top(); // left >= top
        //         int currWidth = i - left - 1;
        //         int currHeight = min(height[left], height[i]) - height[top];
        //         ans += currWidth * currHeight;
        //     }
        //     stk.push(i);
        // }
        // return ans;
        // 方法四：双指针法，时间O（n），空间O（1），可以使用双指针和两个变量代替两个数组，维护两个左右指针，两个leftmax，rightmax变量
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            }
            else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};