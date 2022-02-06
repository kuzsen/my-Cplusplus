#include<deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // �ٷ���⣨������⣩�����ȶ��У��󶥶ѣ�����Ԫ��(nums,i),���������ƶ����̲��Ͻ��ұ߽�Ԫ�ؼ������ȶ��У���ʱtop()��һ���ǵ�ǰ�������ڷ�Χ�ڵ����ֵ���п���λ�ڻ���������߽���ߵģ��Ƚ�topԪ�ص��±� �Ƿ�С�� ����������߽��±�i-k�����жϣ������ڵ�ǰ���������У����ȶ���pop(),ֱ����ǰtop()λ�ڻ���������
        // Ҳ��ʹ�õ�������
        // priority_queue<pair<int, int>> pq; // Ĭ��������vector<pair<int,int>>,Ĭ�ϴ���ѣ�C++ priority_queue ���洢pair��Ĭ������ʽ��������first��num����������second��nums�е��±�i������
        // int n = nums.size();
        // vector<int> res;
        // if (n == 0) return res; // ������Ϊ0����ǰ�ж�
        // //  k ������Ч�ģ����������鲻Ϊ�յ�����£�1 �� k �� ��������Ĵ�С��
        // for (int i = 0; i < k; i++) { // �Ƚ������k��Ԫ�ؼ��뵽���ȶ����У���ʼ����������
        //     pq.emplace(nums[i], i); // �˴�������push��emplace���ȹ����ٲ���
        // }
        // res.push_back(pq.top().first);
        // for (int i = k; i < n; i++) {
        //     pq.emplace(nums[i], i);
        //     while (pq.top().second <= i - k) { // ��ǰ���ȶ����е����ֵ�ڻ���������߽�����
        //         pq.pop();
        //     }
        //     res.push_back(pq.top().first);
        // }
        // return res;

        // �������У�ͷ����β�������Ե�����˫�˶��У���С����洢������±�i��ͬʱ��Щ�±��Ӧ��num�ϸ񵥵�ݼ��������������ڵ����ֵ��Ϊ�������е�ͷ��
        // ����https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/dong-hua-yan-shi-dan-diao-dui-lie-jian-z-unpy/
        deque<int> dq; // https://blog.csdn.net/qq_38665104/article/details/82191939?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164415842016780269823733%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164415842016780269823733&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-82191939.pc_search_insert_ulrmf&utm_term=C%2B%2B%E4%B8%ADqueue&spm=1018.2226.3001.4187 deque���Է������˲��ҿ����ڶ��׺Ͷ�βɾ���Ͳ���Ԫ��
        vector<int> res; // ���������Ϊ�������ڵĸ�����nums.size() - k + 1��
        for (int right = 0; right < nums.size(); right++) { // ���������ұ߽粻������
            // ������в�Ϊ���ҵ�ǰ����Ԫ�ش��ڵ��ڶ�β��Ӧ��Ԫ�أ��򽫶�βԪ���Ƴ���
            // ֱ��������Ϊ�ջ�ǰ����Ԫ��С���µĶ�βԪ��
            while (!dq.empty() && nums[right] >= nums[dq.back()]) {
                dq.pop_back();
            }
            // ����β�����뵥���ݼ���ӦԪ���±�
            dq.push_back(right);

            // ���㻬��������߽�
            int left = right - k + 1;

            // ������Ԫ�ص��±�С�ڻ����������߽�leftʱ
            // ��ʾ���׶�ӦԪ��(�����������ֵ)�Ѿ����ٻ��������ڣ���˽���Ӷ����Ƴ�
            while (dq.front() < left) {
                dq.pop_front();
            }

            // ���������±��0��ʼ����˵������ұ߽�  right+1  ���ڵ��ڴ��ڴ�Сkʱ
            // ��ζ�Ŵ����γɡ���ʱ������Ԫ�ؾ��Ǹô����ڵ����ֵ, �˺�ÿ���ƶ���Ҫ���һ�����
            if (right + 1 >= k) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};