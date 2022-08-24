#include <iostream>
#include <vector>
using namespace std;

// �ѻ���ʹ��ǰ����iλ�õ�Ԫ�أ���Ϊ��ǰ���ڵ㣬���������Һ���
void adjust_heap(vector<int>& arr, int ind, int n) {
	int left = 2 * ind + 1;
	int right = 2 * ind + 2;
	int curMax = ind; // Ѱ�����������и����ֵ
	if (left < n && arr[left] > arr[curMax]) {
		curMax = left;
	}
	if (right < n && arr[right] > arr[curMax]) {
		curMax = right;
	}
	if (curMax != ind) { // ˵����ǰind����/��������ֵ���ڵ�ǰind������ǰind������򣬲��õ������˳�����
		swap(arr[ind], arr[curMax]);
		adjust_heap(arr, curMax, n); // ������arr[curMax]��Ϊ���ڵ㣬�������������Աȣ�
	}
}


void heap_sort(vector<int>& arr, int n) {
	// 1���ӵ�һ����Ҷ�ӽڵ�arr[i]��ʼ����ʼ�������󶥶�
	for (int i = n / 2 - 1; i >= 0; i--) {
		adjust_heap(arr, i, n);
	}
	// 2������
	// 2-1�����������һ��Ԫ�أ��룬 �Ѷ�Ԫ�ؽ�������ʱ�������һ��Ԫ�ؼ�Ϊ���ֵ��
	// 2-2, ����ĳ���n��һ����ǰn-1��Ԫ���ٽ��жѻ�
	for (int i = n - 1; i >= 0; i--) {
		// 2-1��i��ʾ���һ��Ԫ���±�
		swap(arr[0], arr[i]); 

		// 2-2��i��ʾ��������Ҫ�ٴν��жѻ�������ĳ���
		adjust_heap(arr, 0, i); 
	}
}

int main()
{
	// �����򣬴󶥶Ѵ�С����������������ԭ�����������±�������ȫ������
	vector<int> arr = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
	int len = arr.size(); 
	
	heap_sort(arr, len);

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	system("pause");
	system("cls");
	return 0;
}
