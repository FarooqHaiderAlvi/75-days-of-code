
#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();

      vector<bool> seen(n, false);
      seen[0] = true;

      stack<int> st;
      st.push(0);

      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (int nei : rooms[node]) {
          if (!seen[nei]) {
            seen[nei] = true;
            st.push(nei);
          }
        }
      }

      for (bool v : seen) {
        if (!v) return false;
      }

      return true;
    }

    // my version iterative approach
  bool canVisitAllRooms(vector<vector<int>>& rooms) {

    int n = rooms.size();
    vector<bool> visitedRooms(n, false);
    visitedRooms[0] = true;

    bool changed = true;

    while (changed) {
      changed = false;

      for (int i = 0; i < n; i++) {
        if (visitedRooms[i]) {

          for (int key : rooms[i]) {
            if (!visitedRooms[key]) {
              visitedRooms[key] = true;
              changed = true;
            }
          }

        }
      }
    }
    for (bool v : visitedRooms) {
      if (!v) return false;
    }

    return true;
  }
};

int main() {
  vector<vector<int>> rooms = { {6,7,8},{5,4,9},{},{8},{4},{},{1,9,2,3},{7},{6,5},{2,3,1} };
  Solution obj;
  cout<< obj.canVisitAllRooms(rooms);
  return 0;
}