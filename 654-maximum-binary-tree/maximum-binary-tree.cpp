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
    TreeNode* buildMaxTree(vector<int>& nums, int l, int r) {
    if(l > r) return nullptr;
    int maxIdx = l;
    for(int i = l+1; i <= r; i++)
        if(nums[i] > nums[maxIdx]) maxIdx = i;
    
    TreeNode* root = new TreeNode(nums[maxIdx]);
    root->left = buildMaxTree(nums, l, maxIdx-1);
    root->right = buildMaxTree(nums, maxIdx+1, r);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return buildMaxTree(nums, 0, nums.size()-1);
}
};