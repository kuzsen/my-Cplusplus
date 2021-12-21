class Solution {
public:
    int trap(vector<int>& height) {
        // // ����������ͬʱ�ҵ�heigth[i]�������ߵ����heigth����heigth[i]�ܽ�min(l_max,r_max)- height[i]��������ˮ
        // int n = height.size();
        // int res = 0;
        // for (int i = 1; i < n - 1; ++i) { // ���ұ߽粻���ǣ�
        //     int l_max = 0, r_max = 0;
        //     for (int j = i; j >= 0; j--) { // j = i ��ʼ��ʾheight[i]Ҳ�������ֵ�ıȽ�
        //         l_max = max(l_max, height[j]);
        //     }
        //     for (int j = i; j < n; j++) {
        //         r_max = max(r_max, height[j]);
        //     }
        //     // if(l_max > height[i] && r_max > height[i]) { // ʡȥ����жϣ�ֱ�ӽ�height[i]��ֵ���뵽�������������ֵ�Ĺ���
        //     //     res += (min(l_max, r_max) - height[i]);
        //     // }
        //     res += min(l_max, r_max) - height[i];
        // }
        // return res;

        // // �ٷ���⣺��̬�滮��O��n��ʱ�����ÿ��λ����ߡ��ұߵ����ֵ����O��n���ռ����齫��洢
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

        // ������������ջ�����ٷ���⡪��������⣬����height����O��n��ʱ�䣬����ջ�ռ�O(N)���Ӷ�
        // int ans = 0;
        // stack<int> stk;  // ջ�׵�ջ���±��Ӧ��Ԫ��ֵ�ݼ�
        // int n = height.size();
        // for (int i = 0; i < n; ++i) {
        //     while (!stk.empty() && height[i] > height[stk.top()]) { // i��ʵ�����ұߵ�һ������top��
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
        // �����ģ�˫ָ�뷨��ʱ��O��n�����ռ�O��1��������ʹ��˫ָ����������������������飬ά����������ָ�룬����leftmax��rightmax����
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