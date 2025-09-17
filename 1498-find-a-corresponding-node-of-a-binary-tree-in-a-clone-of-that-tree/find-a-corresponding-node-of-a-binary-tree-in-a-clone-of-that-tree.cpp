class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return nullptr;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({original, cloned});

        while (!q.empty()) {
            auto [o, c] = q.front();
            q.pop();

            if (o == target) return c; // found the target in original

            if (o->left && c->left) q.push({o->left, c->left});
            if (o->right && c->right) q.push({o->right, c->right});
        }
        return nullptr;
    }
};
