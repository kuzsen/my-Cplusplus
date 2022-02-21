#include<iostream>
using namespace std;
#include<vector>
class mysort {
public:
	void quickSort(vector<int> &nums, int l, int r) { // lΪ������ʼ�±꣬rΪnums���鳤��
		if (l >= r - 1) return;
		int left = l, right = r - 1;
		int piv = nums[left]; // �����ڱ�
		while (left < right) {
			while (left < right && nums[right] >= piv) right--; // ��ָ�룬��������ɨ�裬
			nums[left] = nums[right]; // ��С��piv�ķŵ����

			while (left < right && nums[left] <= piv) left++;
			nums[right] = nums[left];
		}
		// �����ڱ�
		nums[left] = piv;
		// �ֱ�ݹ��ڱ���ߺ��ұ�
		quickSort(nums, l, left);
		quickSort(nums, left + 1, r);
	}
};
int main()
{
	// int a[] = { 0,34,66,2,5,95,4,46,27 };
	vector<int> a = { 0,34,66,2,5,95,4,46,27 };
	// mysort().quickSort(a, 0, sizeof(a) / sizeof(int));
	mysort().quickSort(a, 0, a.size());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " "; // print => 0 2 4 5 27 34 46 66 95
	}

	system("pause");
	system("cls");
	return 0;
}
