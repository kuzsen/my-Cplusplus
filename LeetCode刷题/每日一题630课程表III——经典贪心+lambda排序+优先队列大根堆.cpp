#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<queue>
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        /*
        为了上尽可能多的课程，我们应该优先考虑那些结课时间短的课程，因此可以首先将所有课程按照结课时间来从小到大排序。依次遍历每个课程，并累计当前的总计上课时间。
若当前课程无法在其截止日期前上完，则要么不上该门课，要么就在已经上的课程里去除一个比当前课程用时还多的课后，再来上这门课，贪心的想，也就是去掉一个当前上过的课中最费时的课程即可。
        */
        //贪心——上更多的课程
        //自定义排序lambda——将所有课程按照结课时间来从小到大排序
        //优先队列（大根堆）——便于取出课程时长值最大的那门课程
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const auto& b) {
            return a[1] < b[1];//上课时长从小到大排序
            });
        //用于储存所有要上的课程
        priority_queue<int> q;//优先队列默认是大根堆，顶部元素值最大,等价于下一行
        //priority_queue <int, vector<int>, less <int> > q;      
        int sumTime = 0;//记录所有要上课程的时间之和
        for (const vector<int>& course : courses) {
            int duration = course[0];//该课程课时
            int lastday = course[1];//该课程截至结课时间
            if (sumTime + duration <= lastday) {//当前优先队列中所有课程的总时间+当前遍历的课程的课时  小于   当前遍历的课程的结课时间，则也修当前课程
                sumTime += duration;
                q.push(duration);
            }
            else if (!q.empty() && q.top() > duration) {//当前优先队列中所有课程的总时间+当前遍历的课程的课时  大于   当前遍历的课程的结课时间，那么我们找到优先队列中的最大元素 ——即课时最大的一门课，如果它的课时大于当前遍历课程的课时，则将它从待上课程的优先队列中取出，再将当前遍历课程的课时加入
                sumTime -= q.top() - duration;//上课总时间减少(q.top()-duration)
                q.pop();
                q.push(duration);
            }
        }
        return q.size();//待修课程的个数
    }
};

int main()
{

	system("pause");
	system("cls");
	return 0;
}
