#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
 int largestAltitude(vector<int>& gain) {
   int maxAltitude = 0;
   int currentAltitude = 0;

   for (int i = 0; i < gain.size(); i++) {
     currentAltitude += gain[i];
     maxAltitude = max(maxAltitude, currentAltitude);
   }

   return maxAltitude;
 }
};

int main() {
 Solution obj;
 vector<int> vc = { -4,-3,-2,-1,4,3,2 };
 cout << obj.largestAltitude(vc);
}