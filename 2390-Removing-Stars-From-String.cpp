#include <iostream>
using namespace std;
#include <stack>

class Solution {
public:
  string removeStars(string s) {
    string result = "";
    stack<char> st;
    for (char val : s) {
      if (val != '*') {
        st.push(val);
      }
      else
        st.pop();
    }
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution obj;
  cout << obj.removeStars("leet**cod*e");
}