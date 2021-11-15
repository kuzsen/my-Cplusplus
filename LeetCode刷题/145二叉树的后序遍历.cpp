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
	void postorder(TreeNode* root, vector<int>& res) {//注意res一点要引用方式传递
		if (!root) {//递归终止条件
			return;
		}
		postorder(root->left, res);
		postorder(root->right, res);
		res.push_back(root->val);//后序,节点值在“递归序”中第三次出现
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorder(root, res);
		return res;
	}
};
class Solution2 {
public:
	/*
		//维护两个栈：1 压入弹出栈，2收集栈（用于反向输出结果）
		实现步骤：
		若头结点为空，直接返回
		首先将root放入栈1；
		1栈1弹出栈顶元素，记为cur
		2将cur压入栈2
		3如果cur有左/右孩子，现将其左孩子压入栈1，再将其右孩子压入栈1
		4循环前三步
	*/
	vector<int> postorderTraversal(TreeNode* root) {
		//维护两个栈：1 压入弹出栈，2收集栈（结果反向）
		stack<TreeNode*> sta1;
		stack<TreeNode*> sta2;
		TreeNode* cur;
		vector<int> res;
		if (root == nullptr) return res;//若头结点为空，直接返回
		sta1.push(root);//首先将root放入栈1；
		while (!sta1.empty()) {
			cur = sta1.top();//1栈1弹出栈顶元素，记为cur
			sta1.pop();
			sta2.push(cur);//2将cur压入栈2
			if (cur->left) {
				sta1.push(cur->left);//3如果cur有左/右孩子，现将其左孩子压入栈1
			}
			if (cur->right) {//再将其右孩子压入栈1
				sta1.push(cur->right);
			}
		}
		while (!sta2.empty()) {
			res.push_back(sta2.top()->val);//将收集栈中的元素，从栈顶依次插入到vector<int>res中
			sta2.pop();
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

	//auto result = Solution1().postorderTraversal(root);
	auto result = Solution2().postorderTraversal(root);

	for (auto i = 0; i < result.size(); i++)//4 5 2 3 1
	{
		cout << result[i] << " ";
	}
	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}