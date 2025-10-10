#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length())
      return false;

    int w1[26] = { 0 };
    int w2[26] = { 0 };

    // Count frequency of each character in both words
    for (int i = 0; i < word1.length(); i++) {
      w1[word1[i] - 'a']++;
      w2[word2[i] - 'a']++;
    }

    // Check if both words have the same set of characters
    for (int i = 0; i < 26; i++) {
      if ((w1[i] == 0 && w2[i] > 0) || (w1[i] > 0 && w2[i] == 0))
        return false;
    }

    // Sort frequency arrays and compare
    sort(w1, w1 + 26);
    sort(w2, w2 + 26);

    for (int i = 0; i < 26; i++) {
      if (w1[i] != w2[i])
        return false;
    }

    return true;
  }
};

int main() {
  Solution solution;

  // Test case 1: Can be transformed using both operations
  string word1 = "abc";
  string word2 = "bca";
  cout << "Test case 1 (\"" << word1 << "\", \"" << word2 << "\"): "
    << (solution.closeStrings(word1, word2) ? "true" : "false") << endl;

  return 0;
}