#include<iostream>
using namespace std;
#include<vector>
#include<stack>
//构建树节点类——二叉树通用
class  TreeNode
{
public:
	int value;//节点值
	TreeNode* left;//左子树
	TreeNode* right;//右子树
public://构造函数
	TreeNode() : value(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}//常用
	TreeNode(int x, TreeNode* left, TreeNode* right) : value(x), left(left), right(right) {}
};

//中序遍历——递归法，时间和空间都是n^2，这是思路最简单的方法，容易想到并且容易实现。递归的终止条件是当前节点是否为空。首先递归调用遍历左子树，然后访问当前节点，最后递归调用右子树
void inorder(TreeNode* root, vector<int>& res) {
	if (!root) {
		return;
	}
	inorder(root->left, res);
	res.push_back(root->value);
	inorder(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	inorder(root, res);
	return res;
}

//迭代法——时间和空间都是n^2，在迭代方法中，从根节点开始找二叉树的最左节点，将走过的节点保存在一个栈中，找到最左节点后访问，对于每个节点来说，它都是以自己为根的子树的根节点，访问完之后就可以转到右儿子上了。
vector<int> inorderTraversal2(TreeNode* root) {
	vector<int> ret;
	if (root == NULL)return ret;
	TreeNode* curr = root;//当前节点
	stack<TreeNode*> st;
	while (!st.empty() || curr != NULL)//栈不为空or当前节点不为空
	{
		while (curr != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		ret.push_back(curr->value);
		curr = curr->right;
	}
	return ret;
}

//Morris 遍历算法，它能将非递归的中序遍历空间复杂度降为 O(1)O(1)。

int main()
{

	//创建二叉树实例
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left ->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	auto result = inorderTraversal(root);

	for (auto i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	system("pause");
	system("cls");
	return 0;
}
