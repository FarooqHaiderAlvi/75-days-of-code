#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<int> radiant, dire;
    int n = senate.size();

    // Fill initial queues with indices
    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R')
        radiant.push(i);
      else
        dire.push(i);
    }

    // Process until one side is empty
    while (!radiant.empty() && !dire.empty()) {
      int rIndex = radiant.front(); radiant.pop();
      int dIndex = dire.front(); dire.pop();

      // The one with smaller index bans the other and comes back next round
      if (rIndex < dIndex)
        radiant.push(rIndex + n); // next round position
      else
        dire.push(dIndex + n);
    }

    return radiant.empty() ? "Dire" : "Radiant";
  }
};


int main() {
  string s = "DRRD";
  Solution obj;
  cout<<obj.predictPartyVictory(s);

  return 0;
}
