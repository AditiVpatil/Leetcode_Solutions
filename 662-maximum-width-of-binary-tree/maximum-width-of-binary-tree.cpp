class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1}); // root at index 1

        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;   // leftmost index at this level
            long long end = q.back().second;      // rightmost index at this level

            ans = max(ans, end - start + 1);

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                // normalize indices to avoid overflow
                long long offset = idx - start;

                if (node->left)
                    q.push({node->left, 2 * offset});
                if (node->right)
                    q.push({node->right, 2 * offset + 1});
            }
        }

        return (int)ans;
    }
};
