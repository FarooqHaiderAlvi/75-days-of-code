#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    // Calculate the total sum of the array
    for (int num : nums) {
      totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int rightSum = totalSum - leftSum - nums[i];
      if (leftSum == rightSum) {
        return i;
      }
      leftSum += nums[i];
    }

    return -1;
  }
};
int main() {
  Solution obj;
  vector<int> vc = { 1, 7, 3, 6, 5, 6 };
  cout << obj.pivotIndex(vc);
}