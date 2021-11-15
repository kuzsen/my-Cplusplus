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
	void postorder(TreeNode* root, vector<int>& res) {//ע��resһ��Ҫ���÷�ʽ����
		if (!root) {//�ݹ���ֹ����
			return;
		}
		postorder(root->left, res);
		postorder(root->right, res);
		res.push_back(root->val);//����,�ڵ�ֵ�ڡ��ݹ����е����γ���
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
		//ά������ջ��1 ѹ�뵯��ջ��2�ռ�ջ�����ڷ�����������
		ʵ�ֲ��裺
		��ͷ���Ϊ�գ�ֱ�ӷ���
		���Ƚ�root����ջ1��
		1ջ1����ջ��Ԫ�أ���Ϊcur
		2��curѹ��ջ2
		3���cur����/�Һ��ӣ��ֽ�������ѹ��ջ1���ٽ����Һ���ѹ��ջ1
		4ѭ��ǰ����
	*/
	vector<int> postorderTraversal(TreeNode* root) {
		//ά������ջ��1 ѹ�뵯��ջ��2�ռ�ջ���������
		stack<TreeNode*> sta1;
		stack<TreeNode*> sta2;
		TreeNode* cur;
		vector<int> res;
		if (root == nullptr) return res;//��ͷ���Ϊ�գ�ֱ�ӷ���
		sta1.push(root);//���Ƚ�root����ջ1��
		while (!sta1.empty()) {
			cur = sta1.top();//1ջ1����ջ��Ԫ�أ���Ϊcur
			sta1.pop();
			sta2.push(cur);//2��curѹ��ջ2
			if (cur->left) {
				sta1.push(cur->left);//3���cur����/�Һ��ӣ��ֽ�������ѹ��ջ1
			}
			if (cur->right) {//�ٽ����Һ���ѹ��ջ1
				sta1.push(cur->right);
			}
		}
		while (!sta2.empty()) {
			res.push_back(sta2.top()->val);//���ռ�ջ�е�Ԫ�أ���ջ�����β��뵽vector<int>res��
			sta2.pop();
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