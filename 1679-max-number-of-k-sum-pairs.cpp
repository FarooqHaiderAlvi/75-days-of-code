#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] + nums[r] > k) {
        r--;
      }
      else if (nums[l] + nums[r] < k) {
        l++;
      }
      else {
        res++;
        l++;
        r--;
      }
    }
    return res;

  }
};

int main() {
  Solution obj;
  vector<int> vec = { 2, 3, 5, 1, 3 };
  obj.maxOperations(vec, 5);
}