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
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int totalOps = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Count minimum swaps to sort this level
            totalOps += countMinSwaps(level);
        }

        return totalOps;
    }

private:
    int countMinSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {arr[i], i};

        sort(v.begin(), v.end());
        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i)
                continue;

            int cycle = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                cycle++;
            }

            if (cycle > 1)
                swaps += cycle - 1;
        }

        return swaps;
    }
};
