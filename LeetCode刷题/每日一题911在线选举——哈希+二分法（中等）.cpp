#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
	题目描述  https://leetcode-cn.com/problems/online-election/
*/
class TopVotedCandidate {
public:
    vector<int> Times;
    vector<int> curentTimeTops;//实时记录times[i]时刻，选举中领先的候选人的编号

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {//类有参构造函数
        //times.length == persons.length
        unordered_map<int, int> voteCount;//第一个参数key为候选人编号，第二个参数vaule为该候选人得到的票数
        voteCount[-1] = -1;//更新第一个得票候选人用
        int top_person = -1;//更新当前时刻票数最高的候选人编号用
        for (int& p : persons) {
            voteCount[p]++;//候选人p得票数加一
            if (voteCount[p] >= voteCount[top_person]) {//**********注意**********等于的时候，说明p是最近得票的一个候选人，即为领先者
                top_person = p;//如果当前候选人得票数大于最高得票数，更新当前时刻票数最高的候选人编号
            }
            curentTimeTops.push_back(top_person);//实时记录person[i]时刻，选举中领先的候选人的编号
        }
        this->Times = times;
    }

    // int q(int t) {//返回在时刻 t 在选举中领先的候选人的编号
    // //二分法在Times数组[0, 5, 10, 15, 20, 25, 30]查找不大于t=12时刻且离 t 最近的最大元素10
    //     
            /*
            关于lower_bound( )和upper_bound( )的常见用法
            https://blog.csdn.net/qq_40160605/article/details/80150252
            upper_bound:从数组的begin位置到end-1位置二分查找第一个大于t的数字，即为15，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
            */
            //     int pos = upper_bound(Times.begin(), Times.end(), t) - Times.begin() - 1;//-1是因为找到的是第一个大于t=12的元素15下标，而我们需要的是不大于t=12时刻且离 t 最近的最大元素10的下标，所以减一
            //     return curentTimeTops[pos];
            // }
    int q(int t) {//关键信息times 是一个严格递增的有序数组，可以使用二分法查找不大于t的最大值
        int l = 0, r = Times.size() - 1, mid;
        int ans = -1;
        while (l <= r) {
            //mid=(l + r) >> 1;也可
            mid = l + (r - l) / 2;
            if (Times[mid] <= t) {
                ans = mid;//用ans更新不大于t的最大值的下标
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return curentTimeTops[ans];//在时刻 t 在选举中领先的候选人的编号
    }
    // 作者：richyoungzz
    // 链接：https://leetcode-cn.com/problems/online-election/solution/shua-ti-ri-ji-day6-by-richyoungzz-61zt/

};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

int main()
{

	system("pause");
	system("cls");
	return 0;
}
