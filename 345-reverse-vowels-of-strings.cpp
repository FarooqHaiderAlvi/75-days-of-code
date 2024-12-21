#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  string reverseVowels(string s) {

    int p1 = 0, p2 = 0;
    int i = 0;
    int j = s.length() - 1;
    bool f1 = false;
    bool f2 = false;
    while (i <= j) {
      if (!f1 && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
        s[i] == 'O' || s[i] == 'U')) {
        f1 = true;
      }

      if (!f2 && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
        s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
        s[j] == 'O' || s[j] == 'U')) {
        f2 = true;
      }
      if (!f1) i++;
      if (!f2) j--;

      if (f1 && f2) {
        swap(s[i], s[j]);
        f1 = false;
        f2 = false;
        i++;j--;
      }
    }
    return s;
  }
};

int main() {
  string s = "leetcode";
  Solution obj;
  cout<<(obj.reverseVowels(s));
}