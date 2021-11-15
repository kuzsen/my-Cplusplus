#include<iostream>
using namespace std;
#include<vector>
#include<stack>
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

//������������ݹ鷨��ʱ��Ϳռ䶼��n^2������˼·��򵥵ķ����������뵽��������ʵ�֡��ݹ����ֹ�����ǵ�ǰ�ڵ��Ƿ�Ϊ�ա����ȵݹ���ñ�����������Ȼ����ʵ�ǰ�ڵ㣬���ݹ����������
void inorder(TreeNode* root, vector<int>& res) {//ע��resһ��Ҫ���÷�ʽ����
	if (!root) {
		return;
	}
	inorder(root->left, res);
	res.push_back(root->val);//����,�ڵ�ֵ�ڡ��ݹ����еڶ��γ���
	inorder(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	inorder(root, res);
	return res;
}

//����������ʱ��Ϳռ䶼��n^2���ڵ��������У��Ӹ��ڵ㿪ʼ�Ҷ�����������ڵ㣬���߹��Ľڵ㱣����һ��ջ�У��ҵ�����ڵ����ʣ�����ÿ���ڵ���˵�����������Լ�Ϊ���������ĸ��ڵ㣬������֮��Ϳ���ת���Ҷ������ˡ�
vector<int> inorderTraversal2(TreeNode* root) {
	vector<int> ret;
	if (root == NULL)return ret;
	TreeNode* curr = root;//��ǰ�ڵ�
	stack<TreeNode*> st;
	while (!st.empty() || curr != NULL)//ջ��Ϊ��or��ǰ�ڵ㲻Ϊ��
	{
		while (curr != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		ret.push_back(curr->val);
		curr = curr->right;
	}
	return ret;
}
class Solution3 {
public:
	/*
		ջʵ��
		1ÿ������������������߽�����ѹ��ջ
		2���ε��� ���� ջ��Ԫ��root�����У���ӡ/����root����������ͷ���root
		3���root������������root��������ѭ��ǰ����

	*/
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root) {
			stack<TreeNode*> sta;
			while (!sta.empty() || root != nullptr) {//���ýڵ�root
				if (root != nullptr) {//1ÿ������������������߽�����ѹ��ջ
					sta.push(root);
					root = root->left;
				}
				else {
					root = sta.top();
					sta.pop();
					res.push_back(root->val);//2���ε���ջ��Ԫ��cur�����У���ӡ/����cur
					root = root->right;//3���cur������������cur��������ѭ��ǰ����
				}
			}
		}
		return res;
	}
};

//Morris �����㷨�����ܽ��ǵݹ����������ռ临�ӶȽ�Ϊ O(1)O(1)��

int main()
{

	//����������ʵ��
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left ->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	//auto result = inorderTraversal(root);
	auto result =Solution3().inorderTraversal(root);

	for (auto i = 0; i < result.size(); i++)//4 2 5 1 3
	{
		cout << result[i] << " ";
	}

	system("pause");
	system("cls");
	return 0;
}
