#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<queue>
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        /*
        Ϊ���Ͼ����ܶ�Ŀγ̣�����Ӧ�����ȿ�����Щ���ʱ��̵Ŀγ̣���˿������Ƚ����пγ̰��ս��ʱ������С�����������α���ÿ���γ̣����ۼƵ�ǰ���ܼ��Ͽ�ʱ�䡣
����ǰ�γ��޷������ֹ����ǰ���꣬��Ҫô���ϸ��ſΣ�Ҫô�����Ѿ��ϵĿγ���ȥ��һ���ȵ�ǰ�γ���ʱ����Ŀκ����������ſΣ�̰�ĵ��룬Ҳ����ȥ��һ����ǰ�Ϲ��Ŀ������ʱ�Ŀγ̼��ɡ�
        */
        //̰�ġ����ϸ���Ŀγ�
        //�Զ�������lambda���������пγ̰��ս��ʱ������С��������
        //���ȶ��У�����ѣ���������ȡ���γ�ʱ��ֵ�������ſγ�
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const auto& b) {
            return a[1] < b[1];//�Ͽ�ʱ����С��������
            });
        //���ڴ�������Ҫ�ϵĿγ�
        priority_queue<int> q;//���ȶ���Ĭ���Ǵ���ѣ�����Ԫ��ֵ���,�ȼ�����һ��
        //priority_queue <int, vector<int>, less <int> > q;      
        int sumTime = 0;//��¼����Ҫ�Ͽγ̵�ʱ��֮��
        for (const vector<int>& course : courses) {
            int duration = course[0];//�ÿγ̿�ʱ
            int lastday = course[1];//�ÿγ̽������ʱ��
            if (sumTime + duration <= lastday) {//��ǰ���ȶ��������пγ̵���ʱ��+��ǰ�����Ŀγ̵Ŀ�ʱ  С��   ��ǰ�����Ŀγ̵Ľ��ʱ�䣬��Ҳ�޵�ǰ�γ�
                sumTime += duration;
                q.push(duration);
            }
            else if (!q.empty() && q.top() > duration) {//��ǰ���ȶ��������пγ̵���ʱ��+��ǰ�����Ŀγ̵Ŀ�ʱ  ����   ��ǰ�����Ŀγ̵Ľ��ʱ�䣬��ô�����ҵ����ȶ����е����Ԫ�� ��������ʱ����һ�ſΣ�������Ŀ�ʱ���ڵ�ǰ�����γ̵Ŀ�ʱ�������Ӵ��Ͽγ̵����ȶ�����ȡ�����ٽ���ǰ�����γ̵Ŀ�ʱ����
                sumTime -= q.top() - duration;//�Ͽ���ʱ�����(q.top()-duration)
                q.pop();
                q.push(duration);
            }
        }
        return q.size();//���޿γ̵ĸ���
    }
};

int main()
{

	system("pause");
	system("cls");
	return 0;
}
