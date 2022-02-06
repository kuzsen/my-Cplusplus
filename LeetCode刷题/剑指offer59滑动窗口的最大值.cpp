#include<deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 官方题解（不难理解）：优先队列，大顶堆，插入元素(nums,i),滑动窗口移动过程不断将右边界元素加入优先队列，此时top()不一定是当前滑动窗口范围内的最大值，有可能位于滑动窗口左边界左边的，比较top元素的下标 是否小于 滑动窗口左边界下标i-k即可判断，若不在当前滑动窗口中，优先队列pop(),直到当前top()位于滑动窗口中
        // 也可使用单调队列
        // priority_queue<pair<int, int>> pq; // 默认容器是vector<pair<int,int>>,默认大根堆，C++ priority_queue 当存储pair的默认排序方式：是先以first（num）排序再以second（nums中的下标i）排序
        // int n = nums.size();
        // vector<int> res;
        // if (n == 0) return res; // 当数组为0，提前判断
        // //  k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
        // for (int i = 0; i < k; i++) { // 先将最左边k个元素加入到优先队列中，初始化滑动窗口
        //     pq.emplace(nums[i], i); // 此处不能用push，emplace是先构造再插入
        // }
        // res.push_back(pq.top().first);
        // for (int i = k; i < n; i++) {
        //     pq.emplace(nums[i], i);
        //     while (pq.top().second <= i - k) { // 当前优先队列中的最大值在滑动窗口左边界的左边
        //         pq.pop();
        //     }
        //     res.push_back(pq.top().first);
        // }
        // return res;

        // 单调队列：头部和尾部都可以弹出的双端队列，从小到大存储数组的下标i，同时这些下标对应的num严格单点递减，即滑动窗口内的最大值，为单调队列的头部
        // 动画https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/dong-hua-yan-shi-dan-diao-dui-lie-jian-z-unpy/
        deque<int> dq; // https://blog.csdn.net/qq_38665104/article/details/82191939?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164415842016780269823733%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164415842016780269823733&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-82191939.pc_search_insert_ulrmf&utm_term=C%2B%2B%E4%B8%ADqueue&spm=1018.2226.3001.4187 deque可以访问两端并且可以在队首和队尾删除和插入元素
        vector<int> res; // 结果个数即为滑动窗口的个数，nums.size() - k + 1个
        for (int right = 0; right < nums.size(); right++) { // 滑动窗口右边界不断右移
            // 如果队列不为空且当前考察元素大于等于队尾对应的元素，则将队尾元素移除。
            // 直到，队列为空或当前考察元素小于新的队尾元素
            while (!dq.empty() && nums[right] >= nums[dq.back()]) {
                dq.pop_back();
            }
            // 队列尾部插入单调递减对应元素下标
            dq.push_back(right);

            // 计算滑动窗口左边界
            int left = right - k + 1;

            // 当队首元素的下标小于滑动窗口左侧边界left时
            // 表示队首对应元素(单调队列最大值)已经不再滑动窗口内，因此将其从队首移除
            while (dq.front() < left) {
                dq.pop_front();
            }

            // 由于数组下标从0开始，因此当窗口右边界  right+1  大于等于窗口大小k时
            // 意味着窗口形成。此时，队首元素就是该窗口内的最大值, 此后每次移动都要输出一个结果
            if (right + 1 >= k) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};