#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//class Solution {
//public:
//
//  int binarySearch(vector<int>& arr, int left, int right, double target) {
//    if (left > right) return -1;
//
//    int mid = left + (right - left) / 2;
//
//    if (arr[mid] >= target) {
//      if (mid == 0 || arr[mid - 1] < target)
//        return mid;  // first element >= target
//      else
//        return binarySearch(arr, left, mid - 1, target);
//    }
//    else {
//      return binarySearch(arr, mid + 1, right, target);
//    }
//  }
//
//  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//    vector<int> res;
//    sort(potions.begin(), potions.end());
//
//    for (int i = 0; i < spells.size(); i++) {
//      double target = (double)success / spells[i];
//      int idx = binarySearch(potions, 0, potions.size() - 1, target);
//      if (idx != -1) {
//        res.push_back(potions.size() - idx); // all potions from idx to end
//      }
//      else {
//        res.push_back(0); // no successful pairs
//      }
//    }
//
//    return res;
//  }
//};

class Solution {
public:

  static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int freq[100001] = { 0 }, pMax = 0;
    for (int p : potions) {
      freq[p]++;
      pMax = max(pMax, p);
    }

    partial_sum(freq, freq + pMax + 1, freq);

    const int n = spells.size(), m = potions.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
      const int spell = spells[i];
      const long long k = (success + spell - 1) / spell;
      if (k <= pMax) {
        result[i] = m - (k >= 1 ? freq[k - 1] : 0);
      }
    }
    return result;
  }
};

int main() {
  vector<int> spells = { 3,1,2 };
  vector<int> potions = { 8,5,8 };
  Solution sol;
  vector<int> ans = sol.successfulPairs(spells, potions, 16);

  for (int x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}