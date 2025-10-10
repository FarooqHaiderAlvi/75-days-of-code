#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;
    map<vector<int>, int> rowMap;

    for (int i = 0; i < n; i++) {
      rowMap[grid[i]]++;
    }

    for (int j = 0; j < n; j++) {
      vector<int> col;
      for (int i = 0; i < n; i++) {
        col.push_back(grid[i][j]);
      }
      if (rowMap.find(col) != rowMap.end()) {
        count += rowMap[col];
      }
    }

    return count;
  }
};

int main() {
  Solution solution;

  // Test case 1
  vector<vector<int>> grid1 = {
      {3, 2, 1},
      {1, 7, 6},
      {2, 7, 7}
  };
  cout << "Test case 1 result: " << solution.equalPairs(grid1) << endl;

  // Test case 2
  vector<vector<int>> grid2 = {
      {3, 1, 2, 2},
      {1, 4, 4, 5},
      {2, 4, 2, 2},
      {2, 4, 2, 2}
  };
  cout << "Test case 2 result: " << solution.equalPairs(grid2) << endl;

  // Test case 3 - single element
  vector<vector<int>> grid3 = { {5} };
  cout << "Test case 3 result: " << solution.equalPairs(grid3) << endl;

  return 0;
}