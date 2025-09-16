class Solution {
public:
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        
        // Traverse right first
        convertBST(root->right);
        
        // Update current node
        sum += root->val;
        root->val = sum;
        
        // Traverse left
        convertBST(root->left);
        
        return root;
    }
};
