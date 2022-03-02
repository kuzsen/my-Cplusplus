#include <iostream>>
#include <vector>
#include <algorithm>
// https://leetcode-cn.com/leetbook/read/meituan/oh1sq3/
/*小美的一个兼职是美团的一名跑腿代购员，她有 n 个订单可以接，订单编号是 1~n ，但是因为订单的时效性，他只能选择其中 m 个订单接取，精明的小美当然希望自己总的获利是最大的，已知，一份订单会提供以下信息，跑腿价格 v ，商品重量 w kg，商品每重 1kg ，代购费用要加 2 元，而一份订单可以赚到的钱是跑腿价格和重量加价之和。小美可是开兰博基尼送货的人，所以自然不会在意自己会累这种事情。请问小美应该选择哪些订单，使得自己获得的钱最多。
请你按照选择的订单编号的从小到大顺序，如果存在多种方案，输出订单编号字典序较小的方案
输入：
- 输入第一行包含两个正整数 n，m，表示订单的数量和小美可以接的订单数量。
- 接下来有 n 行，第 i 行表示 i-1 号订单的信息。每行有两个正整数 v 和 w  ，表示一个订单的跑腿价格和商品重量。
输出：
- 输出包含 m 个 1~n 之间的正整数，中间用空格隔开，表示选择的订单编号。

输入：
	 5 2
	 5 10
	 8 9
	 1 4
	 7 9
	 6 10
输出：2 5

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
	sort(profit.begin(), profit.end(), [](const pp& a, const pp& b) { // lambda自定义排序
		if (a.first == b.first) {
			return a.second < b.second; // 利益都相等，选择编号较小的
		}
		else return a.first > b.first; // 利益较大的
	});
	vector<int> res;
	for (int i = 0; i < m; i++) {
		res.push_back(profit[i].second); // 将利益较大的下标返回
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
