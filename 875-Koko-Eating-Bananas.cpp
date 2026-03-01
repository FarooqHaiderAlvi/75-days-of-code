#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canFinish(piles, h, mid)) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  bool canFinish(vector<int>& piles, int h, int k) {
    long long totalHours = 0;

    for (int bananas : piles) {
      totalHours += (bananas + k - 1) / k;
    }

    return totalHours <= h;
  }
};



int main() {

  vector<int> arr = { 30,11,23,4,20 };
  int k = 4;
  Solution sol;
  int minSpeed = sol.minEatingSpeed(arr, k);
  cout << minSpeed << endl;
  return 0;

}