#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();

    vector<int> res(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && temps[i] > temps[st.top()]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }

    return res;
  }
};
  

int main() {

  vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
  Solution obj;

  vector<int>days = obj.dailyTemperatures(temperatures);

  for (int i = 0;i < days.size();i++) {
    cout << days[i];
  }

}