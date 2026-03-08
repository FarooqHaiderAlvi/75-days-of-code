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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) return false;
        if(root->val== targetSum && !root->left && !root->right) return true;
        if(root->left)  root->left->val+=root->val;
        if(root->right) root->right-> val+= root->val;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right,targetSum);
    }
};