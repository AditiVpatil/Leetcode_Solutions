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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while (!q.empty()) {
            auto [n1, n2] = q.front();
            q.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2 || n1->val != n2->val) return false;

            bool normal = same(n1->left, n2->left) && same(n1->right, n2->right);
            bool flipped = same(n1->left, n2->right) && same(n1->right, n2->left);

            if (normal) {
                q.push({n1->left, n2->left});
                q.push({n1->right, n2->right});
            } 
            else if (flipped) {
                q.push({n1->left, n2->right});
                q.push({n1->right, n2->left});
            } 
            else {
                return false;
            }
        }

        return true;
    }

private:
    bool same(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->val == b->val;
    }
};
