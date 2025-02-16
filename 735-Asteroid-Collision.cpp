#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<char> st;

    for (char ch : s) {
      if (ch != ']') {
        st.push(ch); // Push everything except ']'
      }
      else {
        // Extract the encoded string
        string encodedString = "";
        while (!st.empty() && st.top() != '[') {
          encodedString += st.top();
          st.pop();
        }

        // Remove the '[' from the stack
        if (!st.empty() && st.top() == '[') {
          st.pop();
        }

        // Extract the number
        string numStr = "";
        while (!st.empty() && isdigit(st.top())) {
          numStr += st.top();
          st.pop();
        }

        // Reverse the extracted number and encoded string
        reverse(numStr.begin(), numStr.end());
        reverse(encodedString.begin(), encodedString.end());

        // Convert the number string to an integer
        int num = numStr.empty() ? 1 : stoi(numStr);

        // Build the decoded string
        string decodedString = "";
        for (int i = 0; i < num; i++) {
          decodedString += encodedString;
        }

        // Push the decoded string back onto the stack
        for (char c : decodedString) {
          st.push(c);
        }
      }
    }

    // Build the final result
    string result = "";
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
    Solution obj;
   cout<< obj.decodeString("100[leetcode]");
}