/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int returnSum(TreeNode* root, long targetSum, long currentSum) {
        if (!root) return 0;

        currentSum += root->val;

        int count = 0;
        if (currentSum == targetSum)
            count++;

        count += returnSum(root->left, targetSum, currentSum);
        count += returnSum(root->right, targetSum, currentSum);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        return returnSum(root, targetSum, 0) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};