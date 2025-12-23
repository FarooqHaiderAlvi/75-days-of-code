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
    int preOrderTraversal(TreeNode* node, int currentMax) {
        if (!node) return 0;
        
        int count = 0;
        
        // Check if current node is good
        if (node->val >= currentMax) {
            count = 1;
            currentMax = node->val; // Update the maximum for the path
        }
        

        count += preOrderTraversal(node->left, currentMax);
        count += preOrderTraversal(node->right, currentMax);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return preOrderTraversal(root, root->val);
    }
};
