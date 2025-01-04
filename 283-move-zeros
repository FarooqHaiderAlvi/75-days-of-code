#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  void moveZeroes(vector<int>& nums) {

    int size = nums.size() - 1;
    int count = 0, i = 0;
    // fill non zero elements in nums
    while (i <= size) {
      if (nums[i] != 0)
        nums[count++] = nums[i];
      i++;
    }
    // append zeros to the total size of array
    while (count <= size) {
      nums[count++] = 0;
    }
  }
};

int main() {
  	Solution obj;
  	vector<int> vec = { 2,3,0,4,0,5 };
  	obj.moveZeroes(vec);
}