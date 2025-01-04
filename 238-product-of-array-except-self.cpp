#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> result(size, 1);

    // Step 1: Compute left products and store in result
    int leftProduct = 1;
    for (int i = 0; i < size; i++) {
      result[i] = leftProduct;
      leftProduct *= nums[i];
    }

    // Step 2: Compute right products and multiply with result
    int rightProduct = 1;
    for (int i = size - 1; i >= 0; i--) {
      result[i] *= rightProduct;
      rightProduct *= nums[i];
    }
    return result;
  }
};

int main() {
	Solution obj;
	vector<int> vec = { 2,3,4,5 };
	vector<int>result = obj.productExceptSelf(vec);

}