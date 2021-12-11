#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
	��Ŀ����  https://leetcode-cn.com/problems/online-election/
*/
class TopVotedCandidate {
public:
    vector<int> Times;
    vector<int> curentTimeTops;//ʵʱ��¼times[i]ʱ�̣�ѡ�������ȵĺ�ѡ�˵ı��

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {//���вι��캯��
        //times.length == persons.length
        unordered_map<int, int> voteCount;//��һ������keyΪ��ѡ�˱�ţ��ڶ�������vauleΪ�ú�ѡ�˵õ���Ʊ��
        voteCount[-1] = -1;//���µ�һ����Ʊ��ѡ����
        int top_person = -1;//���µ�ǰʱ��Ʊ����ߵĺ�ѡ�˱����
        for (int& p : persons) {
            voteCount[p]++;//��ѡ��p��Ʊ����һ
            if (voteCount[p] >= voteCount[top_person]) {//**********ע��**********���ڵ�ʱ��˵��p�������Ʊ��һ����ѡ�ˣ���Ϊ������
                top_person = p;//�����ǰ��ѡ�˵�Ʊ��������ߵ�Ʊ�������µ�ǰʱ��Ʊ����ߵĺ�ѡ�˱��
            }
            curentTimeTops.push_back(top_person);//ʵʱ��¼person[i]ʱ�̣�ѡ�������ȵĺ�ѡ�˵ı��
        }
        this->Times = times;
    }

    // int q(int t) {//������ʱ�� t ��ѡ�������ȵĺ�ѡ�˵ı��
    // //���ַ���Times����[0, 5, 10, 15, 20, 25, 30]���Ҳ�����t=12ʱ������ t ��������Ԫ��10
    //     
            /*
            ����lower_bound( )��upper_bound( )�ĳ����÷�
            https://blog.csdn.net/qq_40160605/article/details/80150252
            upper_bound:�������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ������t�����֣���Ϊ15���ҵ����ظ����ֵĵ�ַ���������򷵻�end��ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin,�õ��ҵ������������е��±ꡣ
            */
            //     int pos = upper_bound(Times.begin(), Times.end(), t) - Times.begin() - 1;//-1����Ϊ�ҵ����ǵ�һ������t=12��Ԫ��15�±꣬��������Ҫ���ǲ�����t=12ʱ������ t ��������Ԫ��10���±꣬���Լ�һ
            //     return curentTimeTops[pos];
            // }
    int q(int t) {//�ؼ���Ϣtimes ��һ���ϸ�������������飬����ʹ�ö��ַ����Ҳ�����t�����ֵ
        int l = 0, r = Times.size() - 1, mid;
        int ans = -1;
        while (l <= r) {
            //mid=(l + r) >> 1;Ҳ��
            mid = l + (r - l) / 2;
            if (Times[mid] <= t) {
                ans = mid;//��ans���²�����t�����ֵ���±�
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return curentTimeTops[ans];//��ʱ�� t ��ѡ�������ȵĺ�ѡ�˵ı��
    }
    // ���ߣ�richyoungzz
    // ���ӣ�https://leetcode-cn.com/problems/online-election/solution/shua-ti-ri-ji-day6-by-richyoungzz-61zt/

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
