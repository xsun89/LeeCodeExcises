//
// Created by Xin Sun on 2022-03-07.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {

    }
};

int main() {
    Solution s;
    vector<int> source = {1, 2, 4, 6, 13, 24, 56};
    cout << "test" << endl;
    return 0;
}