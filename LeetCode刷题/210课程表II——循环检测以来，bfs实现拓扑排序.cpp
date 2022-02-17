/*
https://mp.weixin.qq.com/s?__biz=MzkxMDMxMjY2OA==&mid=2247483787&idx=1&sn=28741880a1017c7720d90152cdfe8f7a&chksm=c12c1438f65b9d2e879d56410e13d96805c2a98f20a2ff922abc05a4bd60d4bf354a44af0bd6&mpshare=1&scene=24&srcid=02173Jio8gaFLSN327zCMK9D&sharer_sharetime=1645066711114&sharer_shareid=51ac78f9f13b7cad25cc120f95906bed#rd

ѭ������������������򣬽���BFS��ʵ���������򣬶����д洢���Ϊ0�ĵ�
���������㷨���̣�
1 ѡ��ͼ��һ�����Ϊ0�ĵ㣬��¼����
2 ��ͼ��ɾ���õ����������Ϊ���ı�
3 �ظ�1��2��ֱ��ͼΪ�ջ�û�����Ϊ0�ĵ㡣
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses); // �ڽӱ�洢ͼ�ṹ���γ̽ڵ���i >= 0 && i < numCourses ��g[i] = vecror<int>{j,k,...}��ʾ���޿γ�i��������j,k...
        vector<int> indegree(numCourses); // indegree[i]��ʾ�γ�i�����
        vector<int> res; // �������пγ������ŵ�ѧϰ˳��
        for (auto& pre : prerequisites) {
            g[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++; // ���޿γ̵���ȼ�һ
        }
        queue<int> q; // ���Ϊ0�Ŀγ̶���
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) { // bfs
            int preStudy = q.front();
            q.pop();
            res.push_back(preStudy); // ��ѧ���Ϊ0�Ŀγ�
            for (int backStudy : g[preStudy]) {
                indegree[backStudy]--; // ���ڣ��Ѿ���ѧ��preStudy������������пγ�back����Ⱦ���һ
                if (indegree[backStudy] == 0) {
                    q.push(backStudy);
                }
            }
        }
        // ʾ�������� 3, [[1,0],[1,2],[0,1]]�������������{2}, ʵ��Ӧ�����{}����������������пγ�
        // ����res�еĿγ��������пγ̱Ƚ��Ƿ���ȣ��ж��ܷ����������пγ�
        if (res.size() == numCourses) {
            return res;
        }
        else return vector<int> {};
    }
};