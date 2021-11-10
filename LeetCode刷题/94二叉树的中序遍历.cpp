#include<iostream>
using namespace std;
#include<vector>
#include<stack>
//�������ڵ��ࡪ��������ͨ��
class  TreeNode
{
public:
	int value;//�ڵ�ֵ
	TreeNode* left;//������
	TreeNode* right;//������
public://���캯��
	TreeNode() : value(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}//����
	TreeNode(int x, TreeNode* left, TreeNode* right) : value(x), left(left), right(right) {}
};

//������������ݹ鷨��ʱ��Ϳռ䶼��n^2������˼·��򵥵ķ����������뵽��������ʵ�֡��ݹ����ֹ�����ǵ�ǰ�ڵ��Ƿ�Ϊ�ա����ȵݹ���ñ�����������Ȼ����ʵ�ǰ�ڵ㣬���ݹ����������
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
		ret.push_back(curr->value);
		curr = curr->right;
	}
	return ret;
}

//Morris �����㷨�����ܽ��ǵݹ����������ռ临�ӶȽ�Ϊ O(1)O(1)��

int main()
{

	//����������ʵ��
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
