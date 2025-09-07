/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BFS to build parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> que;
        parent[root] = nullptr;
        que.push(root);

        while (!parent.count(p) || !parent.count(q)) {
            TreeNode* node = que.front();
            que.pop();

            if (node->left) {
                parent[node->left] = node;
                que.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                que.push(node->right);
            }
        }

        //  Collect ancestors of p
        unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        // Walk upward from q until we find common ancestor
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }

        return q;
    }
};
