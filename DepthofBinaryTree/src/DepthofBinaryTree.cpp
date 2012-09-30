//============================================================================
// Depth of Binary Tree
// Given a binary tree, find its depth (maximum height).
//============================================================================

#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxHeight(TreeNode *root) {
        if (root == NULL) return 0;
        return (1 + max(maxHeight(root->left), maxHeight(root->right)));
    }
};

int main() {
    return 0;
}
