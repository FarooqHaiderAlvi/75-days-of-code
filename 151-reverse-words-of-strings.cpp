#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string result = "";
    int n = s.length();
    int i = n - 1;

    while (i >= 0) {
      // Skip trailing spaces
      while (i >= 0 && s[i] == ' ') i--;

      if (i < 0) break;

      // Find the end of the current word
      int j = i;

      // Find the start of the current word
      while (i >= 0 && s[i] != ' ') i--;

      // Append the word to the result
      if (!result.empty()) result += ' ';
      result += s.substr(i + 1, j - i);
    }

    return result;
  }
};

int main() {
  Solution solution;
  string input = "   a  good   example  ";
  cout << '"' << solution.reverseWords(input) << '"' << endl;
  return 0;
}
