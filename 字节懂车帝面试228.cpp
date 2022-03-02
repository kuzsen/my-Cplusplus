#include <iostream>>
#include <vector>
#include <algorithm>
// https://leetcode-cn.com/leetbook/read/meituan/oh1sq3/
/*С����һ����ְ�����ŵ�һ�����ȴ���Ա������ n ���������Խӣ���������� 1~n ��������Ϊ������ʱЧ�ԣ���ֻ��ѡ������ m ��������ȡ��������С����Ȼϣ���Լ��ܵĻ��������ģ���֪��һ�ݶ������ṩ������Ϣ�����ȼ۸� v ����Ʒ���� w kg����Ʒÿ�� 1kg ����������Ҫ�� 2 Ԫ����һ�ݶ�������׬����Ǯ�����ȼ۸�������Ӽ�֮�͡�С�����ǿ����������ͻ����ˣ�������Ȼ���������Լ������������顣����С��Ӧ��ѡ����Щ������ʹ���Լ���õ�Ǯ��ࡣ
���㰴��ѡ��Ķ�����ŵĴ�С����˳��������ڶ��ַ����������������ֵ����С�ķ���
���룺
- �����һ�а������������� n��m����ʾ������������С�����ԽӵĶ���������
- �������� n �У��� i �б�ʾ i-1 �Ŷ�������Ϣ��ÿ�������������� v �� w  ����ʾһ�����������ȼ۸����Ʒ������
�����
- ������� m �� 1~n ֮������������м��ÿո��������ʾѡ��Ķ�����š�

���룺
	 5 2
	 5 10
	 8 9
	 1 4
	 7 9
	 6 10
�����2 5

*/
using namespace std;
typedef pair<int, int> pp;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> profit(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		profit[i] = make_pair(a + b * 2, i + 1);
	}
	sort(profit.begin(), profit.end(), [](const pp& a, const pp& b) { // lambda�Զ�������
		if (a.first == b.first) {
			return a.second < b.second; // ���涼��ȣ�ѡ���Ž�С��
		}
		else return a.first > b.first; // ����ϴ��
	});
	vector<int> res;
	for (int i = 0; i < m; i++) {
		res.push_back(profit[i].second); // ������ϴ���±귵��
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < m; i++) {
		cout << res[i] << " ";
	}

	cout << "lzs" << endl;
	system("pause");
	system("cls");
	return 0;
}
