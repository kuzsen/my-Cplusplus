#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
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


class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {//������ʽ��[1] [2,3] [4,5],���Ժܷ���ļ����ÿ�����Ч��������nullptr���ڵ����
        vector <vector <int>> res;
        if (!root) {
            return res;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {//�жϴ�ʱ��ǰ��ڵ��Ƿ�Ϊ��
            int currentLevelSize = q.size();
            res.push_back(vector <int>());//�洢��ǰ��ڵ�ֵ����

            for (int i = 1; i <= currentLevelSize; ++i) {//��ǰ��ڵ����
                auto node = q.front(); q.pop();//���δ�q���е�ͷ��ȡ��currentLevelSize���ڵ㣬�ٽ���valֵ��ӵ�ret�����һ��������res.back();�������Һ��Ӳ��뵽q����β����
                res.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return res;
    }
};
class Solution2 {
    /*
        ʹ�ö��У��Ƚ��ȳ������Ƚ�ͷ�����������
        1�Ӷ���ĩβ�����ڵ㣬��Ϊcur��
        2����cur��val��
        3���cur����/�Һ��ӣ��Ƚ�cur�����Ӽ�����У��ٽ�cur���Һ��Ӽ������
        4ѭ��ǰ����++
    
    */
public:
    vector<int> levelOrder(TreeNode* root) {//������ʽ��[1 2 3 4 5]
        queue<TreeNode*> q;
        vector<int> res;
        if (!root) {
            return res;
        }
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            //cur = q.back();β������
            cur = q.front();
            res.push_back(cur->val);
            q.pop();
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return res;
    }
};
int main()
{
    //����������ʵ��
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result;
    result = Solution2().levelOrder(root);//1 2 3 4 5
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    system("pause");
    system("cls");
    return 0;
}

