#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {};
};
class Solution {
public:
	unordered_map<int, int> findRootIndex;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		if (n == 0) return nullptr;
		if (n == 1) {
			TreeNode* res = new TreeNode(preorder[0]);
			return res;
		}
		for (int i = 0; i < n; i++) {
			findRootIndex[inorder[i]] = i;
		}
		return preAndIn(preorder, inorder, 0, n - 1, 0, n - 1);
	}
	TreeNode* preAndIn(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
		if (pre_l > pre_r) {
			return nullptr;
		}
		TreeNode* curRoot = new TreeNode(preorder[pre_l]); // 前序遍历头节点当前root
		int inRootIndex = findRootIndex[preorder[pre_l]]; // 找到当前root在中序遍历序列中的位置
		// 当前左子树节点个数为inRootIndex - in_l，右子树节点个数为in_r - inRootIndex
		curRoot->left = preAndIn(preorder, inorder, pre_l + 1, pre_l + inRootIndex - in_l, in_l, inRootIndex - 1);
		curRoot->right = preAndIn(preorder, inorder, pre_l + inRootIndex - in_l + 1, pre_r, inRootIndex + 1, in_r);
		return curRoot;
	}
};
int main()
{
	TreeNode* node15 = new TreeNode(15);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node20 = new TreeNode(20, node15, node7);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node3 = new TreeNode(3, node9, node20);
	vector<int> pre = { 3,9,20,15,7 };
	vector<int> in = { 9,3,15,20,7};
	TreeNode* res = Solution().buildTree(pre, in);

	system("pause");
	system("cls");
	return 0;
}
