#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> countMap;
    for (int num : arr) {
      countMap[num]++;
    }
    unordered_set<int> countSet;
    for (pair<int, int> pair : countMap) {
      int count = pair.second;
      if (countSet.find(count) != countSet.end()) {
        return false;
      }
      countSet.insert(count);
    }

    return true;
  }
};

int main() {
  vector<int> vc = { 2,3,4,5,4,5,6,4,5,7 };
  Solution obj;
  cout<<obj.uniqueOccurrences(vc);
}