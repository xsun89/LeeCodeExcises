#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <regex>

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
        vector<int> in;
        vector<vector<int> > out;
        if(root == NULL){
            return out;
        }
        queue<TreeNode*> tempQueue;
        tempQueue.push(root);
        TreeNode* last = root;
        TreeNode* nlast = NULL;

        while(!tempQueue.empty()){
            TreeNode* treeNode = tempQueue.front();
            cout << treeNode->val;
            in.push_back(treeNode->val);
            tempQueue.pop();

            if(treeNode->left != NULL){
                tempQueue.push(treeNode->left);
                nlast = treeNode->left;
            }
            if(treeNode->right != NULL){
                tempQueue.push(treeNode->right);
                nlast = treeNode->right;
            }
            if(last == treeNode){
                last = nlast;
                out.push_back(in);
                vector<int> in;
                cout << endl;
            }
        }

        return out;
    }
};

void createTree(TreeNode *&root)
{
    int val;
    cin >> val;
    if(val == 0) {
        root = NULL;
    }else {
        root = new TreeNode();
        root->val = val;
        createTree(root->left);
        createTree(root->right);
    }
}

void printTree(TreeNode *root)
{
    if(root == NULL){
        return;
    }
    cout << root->val<<endl;
    printTree(root->left);
    printTree(root->right);
}

void getSerilizedTree(TreeNode* root, string &tmp)
{
    if(root == NULL){
        tmp += "#!";
        return;
    }
    tmp += to_string(root->val) + "!";
    getSerilizedTree(root->left, tmp);
    getSerilizedTree(root->right, tmp);

    return;

}

vector<string> getSplitString(string &str, string &strok){
    // Replace each colon with a single space
    const regex pattern(strok);
    const string r = regex_replace(str, pattern, " ");

    cout << "after regex=" << r <<endl;

    std::istringstream ist(r);

    std::vector<string> numbers;
    std::copy(std::istream_iterator<string>(ist), std::istream_iterator<string>(),
              std::back_inserter(numbers));

    return numbers;

}
void createSerilizedTree(TreeNode* root, string &tmp)
{
    string st = string("!");
    vector<string> ret = getSplitString(tmp, st);

    for (string n : ret)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
void destroyTree(TreeNode *root)
{
    if(root !=  NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        cout << "delete " << root->val <<endl;
        delete root;
        //root = NULL;
    }
}

int main() {
    TreeNode *root = new TreeNode();
    root->val = 1;
    TreeNode* tmpLeft = new TreeNode();
    tmpLeft->val = 2;
    root->left = tmpLeft;
    TreeNode* tempRight = new TreeNode();
    tempRight->val = 3;
    root->right = tempRight;

    TreeNode* tmp3Left = new TreeNode();
    tmp3Left->val =6;
    TreeNode* tmp3right = new TreeNode();
    tmp3right->val = 7;

    tmpLeft->left = tmp3Left;
    tmpLeft->right = tmp3right;

    TreeNode* tmp2Left = new TreeNode();
    tmp2Left->val =4;
    TreeNode* tmp2right = new TreeNode();
    tmp2right->val = 5;

    tempRight->left = tmp2Left;
    tempRight->right = tmp2right;


    //createTree(root);
    printTree(root);
    TreePrinter p;
    p.printTree(root);
    string tmp;
    getSerilizedTree(root, tmp);
    cout << "Seri=" << tmp << endl;

    TreeNode *root2 = new TreeNode();
    createSerilizedTree(root2, tmp);
    destroyTree(root);
    return 0;
}