#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
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


class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {//返回形式是[1] [2,3] [4,5],可以很方便的计算出每层的有效（不包括nullptr）节点个数
        vector <vector <int>> res;
        if (!root) {
            return res;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {//判断此时当前层节点是否为空
            int currentLevelSize = q.size();
            res.push_back(vector <int>());//存储当前层节点值容器

            for (int i = 1; i <= currentLevelSize; ++i) {//当前层节点个数
                auto node = q.front(); q.pop();//依次从q队列的头部取出currentLevelSize个节点，再将其val值添加到ret的最后一个容器中res.back();将其左右孩子插入到q队列尾部，
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
        使用队列，先进先出，首先将头结点放入队列中
        1从队列末尾弹出节点，记为cur；
        2处理cur的val；
        3如果cur有左/右孩子，先将cur的左孩子加入队列，再将cur的右孩子加入队列
        4循环前三步++
    
    */
public:
    vector<int> levelOrder(TreeNode* root) {//返回形式是[1 2 3 4 5]
        queue<TreeNode*> q;
        vector<int> res;
        if (!root) {
            return res;
        }
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            //cur = q.back();尾部错误
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
    //创建二叉树实例
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

