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
    int result = 0;

    vector<int> dfs(TreeNode* root, int distance) {
        if (!root) return {};
        if (!root->left && !root->right) return {1}; // leaf → distance 1 to itself

        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);

        // Count valid leaf pairs (one from left, one from right)
        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance)
                    result++;
            }
        }

        // Return distances to upper node (+1)
        vector<int> curr;
        for (int d : left)
            if (d + 1 <= distance)
                curr.push_back(d + 1);
        for (int d : right)
            if (d + 1 <= distance)
                curr.push_back(d + 1);

        return curr;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return result;
    }
};
