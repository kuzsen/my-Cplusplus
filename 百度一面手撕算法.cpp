// ��˺�㷨��
// 1��ʵ�ֹ�ϣ��Ĳ��ҺͲ��룬����д������������
// 2��ʵ�ֶ���������Ĳ��빦�ܣ�д������
// C++�Ӵ��뵽��ִ�г���Ĺ��̣�Ԥ���롢���롢��ࡢ���ӡ������˾�̬�붯̬���ӵ�����
// map��unordered_map������
// Ϊʲômap�ײ��ú�������ش��˺������ƽ�������������

// Ȼ��ͽ����ˣ������ǵ�һ���㷨����д�������ǰ˹��ı���̫���ԣ�


#include <iostream>
#include <vector>
using namespace std;

struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;
    treeNode() : val(0), left(nullptr), right(nullptr) {};
    treeNode(int v) : val(v), left(nullptr), right(nullptr) {};
    treeNode(int v, treeNode* _l, treeNode* _r) : val(v), left(_l), right(_r) {};
};
treeNode* findTree(treeNode* root, treeNode* inNode) {
    if (root == nullptr) return inNode;
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val < inNode->val) root->right = inNode;
        else root->left = inNode;
        return root;
    }
    if (root->left && root->right == nullptr) {
        if (root->val < inNode->val) {
            root->right = inNode;
            return root;
        }
        else {
            return findTree(root->left, inNode);
        }
    }
    if (root->left == nullptr && root->right) {
        if (root->val < inNode->val) {
            return findTree(root->right, inNode);
        }
        else {
            root->left = inNode;
            return root;
        }
    }
    if (root->val < inNode->val) {
        return findTree(root->right, inNode);
    }
    else {
        return findTree(root->left, inNode);
    }
}
int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
}