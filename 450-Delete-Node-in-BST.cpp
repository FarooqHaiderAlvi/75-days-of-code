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
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* tempNodePtr = nullptr;
        TreeNode* nodePtr = root;
        TreeNode* parent = nullptr;

        while (nodePtr) {
            if (nodePtr->val == key) {
                break;
            } else {
                parent = nodePtr;
                if (nodePtr->val > key) {
                    nodePtr = nodePtr->left;
                } else {
                    nodePtr = nodePtr->right;
                }
            }
        }

        if (nodePtr == nullptr)
            return root;

        // Case 1: Node has no child
        if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
            if (parent == nullptr) {
                root = nullptr;
            } else if (parent->left == nodePtr) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete nodePtr;
        }

        // Case 2: Node has only one child
        else if ((nodePtr->left == nullptr) != (nodePtr->right == nullptr)) {

            if (nodePtr->left)
                tempNodePtr = nodePtr->left;
            else
                tempNodePtr = nodePtr->right;

            if (parent == nullptr) {
                root = tempNodePtr;
            } else if (parent->left == nodePtr) {
                parent->left = tempNodePtr;
            } else {
                parent->right = tempNodePtr;
            }
            delete nodePtr;
        }

        // Case 3: Node has both left and right children
        else {
            TreeNode* successorParent = nodePtr;
            TreeNode* successor = nodePtr->right;

            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }

            if (successorParent != nodePtr) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }

            nodePtr->val = successor->val;
            delete successor;
        }

        return root;
    }
};