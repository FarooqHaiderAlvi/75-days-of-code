#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size()-1;

    int maxContainer = 0;
    while (i <= j) {
  
      int volume = height[i] < height[j] ? height[i] * (j-i) : height[j] * (j-i);
      if (volume > maxContainer) maxContainer = volume;
        
      if (height[i] < height[j]) {
        i++;
      }
      else {
        j--;
      }
    }
    return maxContainer;
  }
};

int main() {
  Solution obj;
  vector<int> vec = { 1,8,6,2,5,4,8,3,7 };
  cout<<obj.maxArea(vec);
}