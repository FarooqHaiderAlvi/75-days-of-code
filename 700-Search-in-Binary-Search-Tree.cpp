#include <iostream>
using namespace std;

// TreeNode structure (same as yours)
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Corrected searchBST function
class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL) {
      return NULL;
    }
    else if (val == root->val) {
      return root;
    }
    else if (root->val > val) {
      return searchBST(root->left, val);
    }
    else {
      return searchBST(root->right, val);
    }
  }
};

// Helper function to insert a value into BST
TreeNode* insertBST(TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }

  if (val < root->val) {
    root->left = insertBST(root->left, val);
  }
  else {
    root->right = insertBST(root->right, val);
  }

  return root;
}

// Helper function to create a sample BST
TreeNode* createSampleBST() {
  TreeNode* root = nullptr;

  // Insert values: 4, 2, 7, 1, 3
  root = insertBST(root, 4);
  root = insertBST(root, 2);
  root = insertBST(root, 7);
  root = insertBST(root, 1);
  root = insertBST(root, 3);

  return root;
}

// Helper function to print search result
void printSearchResult(TreeNode* result, int val) {
  if (result != nullptr) {
    cout << "Value " << val << " found in the BST" << endl;
  }
  else {
    cout << "Value " << val << " NOT found in the BST" << endl;
  }
}

// Main function
int main() {
  Solution solution;

  // Create a BST
  TreeNode* root = createSampleBST();

  cout << "Searching in BST: [4, 2, 7, 1, 3]" << endl;
  cout << "---------------------------------" << endl;

  // Test cases
  TreeNode* result;

  // Test 1: Search for value 2 (exists)
  result = solution.searchBST(root, 2);
  printSearchResult(result, 2);
  if (result) {
    cout << "  Found node value: " << result->val << endl;
  }

  cout << endl;

  // Test 2: Search for value 7 (exists)
  result = solution.searchBST(root, 7);
  printSearchResult(result, 7);
  if (result) {
    cout << "  Found node value: " << result->val << endl;
  }

  cout << endl;

  // Test 3: Search for value 5 (doesn't exist)
  result = solution.searchBST(root, 5);
  printSearchResult(result, 5);

  cout << endl;

  // Test 4: Search for value 1 (exists)
  result = solution.searchBST(root, 1);
  printSearchResult(result, 1);
  if (result) {
    cout << "  Found node value: " << result->val << endl;
  }

  cout << endl;

  // Test 5: Search for value 10 (doesn't exist)
  result = solution.searchBST(root, 10);
  printSearchResult(result, 10);

  // Clean up memory (in a real application, you'd want a proper destructor)
  // For simplicity, we're not implementing full cleanup here

  return 0;
}