class MaxQueue {
    // ������һ�����У��Ƚ��ȳ�
    queue<int> q;
    // ά���������ֵ��ʹ��˫�˶��У���β-->���ף���������
    deque<int> d;
public:

    MaxQueue() {

    }

    int max_value() {
        return d.empty() ? -1 : d.front(); // ˫�˶��ж���Ԫ�����
    }

    void push_back(int value) {
        // q.push_back(value);
        q.push(value);
        if (d.empty()) {
            d.push_back(value); // ˫�˶���Ϊ��ʱ��ֱ�Ӳ���
        }
        else {
            while (!d.empty() && d.back() < value) {
                d.pop_back(); // ��β����С�ڲ���value��ֵ
            }
            d.push_back(value); // ��βԪ�ؿ϶�����value
        }
    }

    int pop_front() {
        // return q.empty() ? -1 : q.front();
        if (q.empty()) return -1;
        int remove = q.front();
        q.pop(); // �����е���

        if (remove == d.front()) { // // �жϵ���Ԫ���Ƿ��Ƕ����е����ֵ�������
            d.pop_front(); // ������˫������еĶ������ֵҲ����
        }
        // �������Ԫ��remove С�� ����˫��������ֵd.front()��ʲô����Ҳ����Ҫ����Ϊ���remove��ά������˫�����β����ͷ������������ʱ����Ѿ�������
        return remove;
    }
};

// ����ʵ��һ����ͨ�Ķ��С���������������ѯ���ֵʱ��������
class MaxQueue {
    int q[20000];
    int begin = 0, end = 0;
public:
    MaxQueue() {
    }

    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; ++i)
            ans = max(ans, q[i]);
        return ans;
    }

    void push_back(int value) {
        q[end++] = value;
    }

    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++];
    }
};

//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */