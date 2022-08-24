#include <iostream>
#include <vector>
using namespace std;

// 堆化，使当前数组i位置的元素，作为当前根节点，大于其左右孩子
void adjust_heap(vector<int>& arr, int ind, int n) {
	int left = 2 * ind + 1;
	int right = 2 * ind + 2;
	int curMax = ind; // 寻找左右子树中更大的值
	if (left < n && arr[left] > arr[curMax]) {
		curMax = left;
	}
	if (right < n && arr[right] > arr[curMax]) {
		curMax = right;
	}
	if (curMax != ind) { // 说明当前ind的左/右子树的值大于当前ind，否则当前ind满足规则，不用调整，退出即可
		swap(arr[ind], arr[curMax]);
		adjust_heap(arr, curMax, n); // 继续以arr[curMax]作为根节点，与其左右子树对比，
	}
}


void heap_sort(vector<int>& arr, int n) {
	// 1、从第一个非叶子节点arr[i]开始，初始化建立大顶堆
	for (int i = n / 2 - 1; i >= 0; i--) {
		adjust_heap(arr, i, n);
	}
	// 2、排序
	// 2-1，将数组最后一个元素，与， 堆顶元素交换，此时数组最后一个元素即为最大值；
	// 2-2, 数组的长度n减一，将前n-1个元素再进行堆化
	for (int i = n - 1; i >= 0; i--) {
		// 2-1，i表示最后一个元素下标
		swap(arr[0], arr[i]); 

		// 2-2，i表示交换后，需要再次进行堆化的数组的长度
		adjust_heap(arr, 0, i); 
	}
}

int main()
{
	// 堆排序，大顶堆从小到大排序，利用数组原地排序，数组下标满足完全二叉树
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
