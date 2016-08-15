#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
        // write code here
    }
};

void createTree(TreeNode *&root)
{
    int val;
    cin << val;
    if(val == 0) {
        root = null;
    }else {
        root = new TreeNode();
        root.val = val;
        createTree(root->left);
        createTree(root->right);
    }
}

int main() {
    TreeNode root;
    createTree(root);
    return 0;
}