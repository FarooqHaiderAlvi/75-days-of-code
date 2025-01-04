#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
 vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

   vector<bool> result;
   int maxElement = *max_element(candies.begin(), candies.end());
   for (int i = 0;i < candies.size();i++) {
     if (candies[i] + extraCandies >= maxElement)
       result.push_back(true);
     else
       result.push_back(false);
   }

   return result;
 }
};

int main() {

 vector<int> candies = {2, 3, 5, 1, 3};
 int extraCandies = 3;

}