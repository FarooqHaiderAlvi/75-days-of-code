#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    // Compute initial window sum
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    double maxSum = sum;
    // Sliding window
    for (int i = k; i < nums.size(); i++) {
      sum += nums[i] - nums[i - k];
      if (sum > maxSum) maxSum = sum;
    }
    return maxSum / k;
  }
};

int main() {
	vector<int> vec = { 1,12,-5,-6,50,3 };
	Solution obj;
	cout << obj.findMaxAverage(vec, 4);
}