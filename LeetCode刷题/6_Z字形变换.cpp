#include<iostream>
#include<vector>
#include<string>
using namespace std;
//����һ����������https://leetcode-cn.com/problems/zigzag-conversion/solution/z-zi-xing-bian-huan-by-leetcode/
//˼·��
//ͨ���������ҵ����ַ��������ǿ������ɵ�ȷ���ַ�λ�� Z ����ͼ���е���һ�С�
//
//�㷨��
//���ǿ���ʹ�� \text{ min }(\text{ numRows }, \text{ len }(s))min(numRows, len(s)) ���б�����ʾ Z ����ͼ���еķǿ��С�
//
//�����ҵ��� ss����ÿ���ַ���ӵ����ʵ��С�����ʹ�õ�ǰ�к͵�ǰ���������������Ժ��ʵ��н��и��١�
//
//ֻ�е����������ƶ�����������л������ƶ������������ʱ����ǰ����Żᷢ���ı䡣
//
//���Ӷȷ�����
//ʱ�临�Ӷȣ�O(n)������ n == len(s)
//�ռ临�Ӷȣ�O(n)


string convert(string& s, const int& rownums)
{
	if (rownums == 1)
	{
		return s;
	}
	int len = s.size();
	vector<string> Rows(min(len, rownums));//min(len, rownums)���б��ʾZ����ͼ���ķǿ���
	
	int cur_row = 0;//��ʼ������ǰ�ǵ�0��
	bool goingdown = false;//trueΪ���£�false����

	for (auto c : s)
	{
		Rows[cur_row] += c;//Rows[cur_row]ΪRows�е��ַ���Ԫ�أ�ÿ������һ��
		if (cur_row == 0 || cur_row == rownums - 1)//�����ǰ������������������棬�ı����ƶ��ķ���
		{
			goingdown = !goingdown;
		}
		cur_row += (goingdown ? 1 : -1);//�з������£���ǰ��+1������-1
	}
	string ret;
	for (string Row : Rows)//����ͼ���е�ÿ���ַ���������ƴ�ӵ�һ��
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