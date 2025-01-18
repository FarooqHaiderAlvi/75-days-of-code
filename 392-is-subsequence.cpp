#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {

    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
      if (s[i] == t[j]) {
        i++;j++;
      }
      else {
        j++;
      }
    }
    return i == s.length();
  }
};

int main() {
  Solution obj;
  cout<<obj.isSubsequence("abc", "axbhrck");
}