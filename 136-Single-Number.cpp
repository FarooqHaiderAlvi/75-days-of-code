#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int odd = nums[0];
    for (int i = 1;i < nums.size();i++) {

      odd = odd ^ nums[i];
    }
    return odd;
  }
};


int main() {
  vector<int> a = { 5,5,4 };
  Solution obj;
  cout<< obj.singleNumber(a);
}