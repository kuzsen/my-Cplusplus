class MaxQueue {
    // 首先是一个队列，先进先出
    queue<int> q;
    // 维护队列最大值，使用双端队列，队尾-->队首，单调递增
    deque<int> d;
public:

    MaxQueue() {

    }

    int max_value() {
        return d.empty() ? -1 : d.front(); // 双端队列队首元素最大
    }

    void push_back(int value) {
        // q.push_back(value);
        q.push(value);
        if (d.empty()) {
            d.push_back(value); // 双端队列为空时，直接插入
        }
        else {
            while (!d.empty() && d.back() < value) {
                d.pop_back(); // 队尾弹出小于插入value的值
            }
            d.push_back(value); // 队尾元素肯定大于value
        }
    }

    int pop_front() {
        // return q.empty() ? -1 : q.front();
        if (q.empty()) return -1;
        int remove = q.front();
        q.pop(); // 队列中弹出

        if (remove == d.front()) { // // 判断弹出元素是否是队列中的最大值，如果是
            d.pop_front(); // 将单调双向队列中的队首最大值也弹出
        }
        // 如果弹出元素remove 小于 单调双向队列最大值d.front()，什么操作也不需要，因为这个remove在维护单调双向队列尾部到头部单调不减的时候就已经弹出了
        return remove;
    }
};

// 暴力实现一个普通的队列————基础，查询最大值时遍历计算
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

//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */