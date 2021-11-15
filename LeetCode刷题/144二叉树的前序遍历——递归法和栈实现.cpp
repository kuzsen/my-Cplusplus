#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//构建树节点类——二叉树通用
class  TreeNode
{
public:
	int val;//节点值
	TreeNode* left;//左子树
	TreeNode* right;//右子树
public://构造函数
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}//常用
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {//递归
public:
	void preorder(TreeNode* root, vector<int>& res) {//注意res一点要引用方式传递
		if (!root) {//递归终止条件
			return;
		}
		res.push_back(root->val);//前序,节点值在“递归序”中第一次出现
		preorder(root->left, res);
		preorder(root->right, res);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorder(root, res);
		return res;
	}
};
class Solution2 {
public:
	/*
		栈实现

	一上来先把头结点放到栈中

	1每次从栈中弹出一个节点cur

	2打印/处理cur

	3（如果有左/右孩子的话）先把右孩子压入栈，再把左孩子压入栈

	4循环前3步
	*/
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> sta;
		TreeNode* cur = nullptr;
		if (root == nullptr) return res;
		sta.push(root);
		while (!sta.empty()) {
			cur = sta.top();
			sta.pop();
			res.push_back(cur->val);
			if (cur->right) {
				sta.push(cur->right);
			}
			if (cur->left) {
				sta.push(cur->left);
			}
		}
		return res;
	}
};

int main() {
	//创建二叉树实例
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	auto result = Solution1().preorderTraversal(root);//1 2 4 5 3
	//auto result = Solution2().preorderTraversal(root);

	for (auto i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
