/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
    if (!root) return 0;

    vector<TreeNode*> nodes;
    nodes.push_back(root);

    // use vector like a queue (BFS style)
    for (int i = 0; i < nodes.size(); i++) {
        TreeNode* curr = nodes[i];
        if (curr->left) nodes.push_back(curr->left);
        if (curr->right) nodes.push_back(curr->right);
    }

    return nodes.size();
}

};