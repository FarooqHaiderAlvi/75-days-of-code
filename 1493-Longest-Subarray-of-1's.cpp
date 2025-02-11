#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int k = 1;
    int i = 0, j = 0;
    while (j < nums.size()) {
      if (nums[j++] == 0) {
        k--;
      }
      if (k < 0) {
        if (nums[i++] == 0) {
          k++;
        }
      }
    }
    return j - i - 1;
  }
};

int main() {
  Solution obj;
  vector<int> vec = { 1,1,1,0,0,0,1,1,1,1,0 };
  cout << obj.longestSubarray(vec);
}