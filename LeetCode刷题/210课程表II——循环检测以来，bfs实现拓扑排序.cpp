/*
https://mp.weixin.qq.com/s?__biz=MzkxMDMxMjY2OA==&mid=2247483787&idx=1&sn=28741880a1017c7720d90152cdfe8f7a&chksm=c12c1438f65b9d2e879d56410e13d96805c2a98f20a2ff922abc05a4bd60d4bf354a44af0bd6&mpshare=1&scene=24&srcid=02173Jio8gaFLSN327zCMK9D&sharer_sharetime=1645066711114&sharer_shareid=51ac78f9f13b7cad25cc120f95906bed#rd

循环检测依赖，拓扑排序，借助BFS来实现拓扑排序，队列中存储入度为0的点
拓扑排序算法过程：
1 选择图中一个入度为0的点，记录下来
2 在图中删除该点和所有以它为起点的边
3 重复1和2，直到图为空或没有入度为0的点。
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses); // 邻接表存储图结构，课程节点编号i >= 0 && i < numCourses ，g[i] = vecror<int>{j,k,...}表示先修课程i，才能修j,k...
        vector<int> indegree(numCourses); // indegree[i]表示课程i的入度
        vector<int> res; // 修完所有课程所安排的学习顺序
        for (auto& pre : prerequisites) {
            g[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++; // 后修课程的入度加一
        }
        queue<int> q; // 入度为0的课程队列
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) { // bfs
            int preStudy = q.front();
            q.pop();
            res.push_back(preStudy); // 先学入度为0的课程
            for (int backStudy : g[preStudy]) {
                indegree[backStudy]--; // 由于，已经先学了preStudy，它后面的所有课程back的入度均减一
                if (indegree[backStudy] == 0) {
                    q.push(backStudy);
                }
            }
        }
        // 示例：输入 3, [[1,0],[1,2],[0,1]]，按照以上输出{2}, 实际应该输出{}，即不可能完成所有课程
        // 根据res中的课程数与所有课程比较是否相等，判断能否合理完成所有课程
        if (res.size() == numCourses) {
            return res;
        }
        else return vector<int> {};
    }
};