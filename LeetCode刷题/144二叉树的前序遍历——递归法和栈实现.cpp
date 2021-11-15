#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//�������ڵ��ࡪ��������ͨ��
class  TreeNode
{
public:
	int val;//�ڵ�ֵ
	TreeNode* left;//������
	TreeNode* right;//������
public://���캯��
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}//����
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution1 {//�ݹ�
public:
	void preorder(TreeNode* root, vector<int>& res) {//ע��resһ��Ҫ���÷�ʽ����
		if (!root) {//�ݹ���ֹ����
			return;
		}
		res.push_back(root->val);//ǰ��,�ڵ�ֵ�ڡ��ݹ����е�һ�γ���
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
		ջʵ��

	һ�����Ȱ�ͷ���ŵ�ջ��

	1ÿ�δ�ջ�е���һ���ڵ�cur

	2��ӡ/����cur

	3���������/�Һ��ӵĻ����Ȱ��Һ���ѹ��ջ���ٰ�����ѹ��ջ

	4ѭ��ǰ3��
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
	//����������ʵ��
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
