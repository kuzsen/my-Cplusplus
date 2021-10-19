#include<iostream>
#include<vector>
#include<string>
using namespace std;
//方法一：按行排序https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/
//思路：
//通过从左向右迭代字符串，我们可以轻松地确定字符位于 Z 字形图案中的哪一行。
//
//算法：
//我们可以使用 \text{ min }(\text{ numRows }, \text{ len }(s))min(numRows, len(s)) 个列表来表示 Z 字形图案中的非空行。
//
//从左到右迭代 ss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
//
//只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
//
//复杂度分析：
//时间复杂度：O(n)，其中 n == len(s)
//空间复杂度：O(n)


string convert(string& s, const int& rownums)
{
	if (rownums == 1)
	{
		return s;
	}
	int len = s.size();
	vector<string> Rows(min(len, rownums));//min(len, rownums)个列表表示Z字形图案的非空行
	
	int cur_row = 0;//初始化，当前是第0行
	bool goingdown = false;//true为向下，false向上

	for (auto c : s)
	{
		Rows[cur_row] += c;//Rows[cur_row]为Rows中的字符串元素，每个代表一行
		if (cur_row == 0 || cur_row == rownums - 1)//如果当前行在最上面或者最下面，改变行移动的方向
		{
			goingdown = !goingdown;
		}
		cur_row += (goingdown ? 1 : -1);//行方向向下，当前行+1，否则-1
	}
	string ret;
	for (string Row : Rows)//遍历图案中的每行字符，将他们拼接到一起
	{
		ret += Row;
	}
	return ret;
}

int main()
{
	string s1;
	int row1 = 3 ;
	getline(cin, s1);

	cout << convert(s1, row1) << endl;

	system("pause");
	system("cls");
	return 0;
}