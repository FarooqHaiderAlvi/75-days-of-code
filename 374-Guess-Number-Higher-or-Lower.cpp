#include <iostream>
using namespace std;


class Solution {

private: 
  int pickedNumber;
  int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
  }
public:
  Solution(int n) {
    pickedNumber = n;
  }
  int guessNumber(int n) {
    int low = 1, high = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int res = guess(mid);

      if (res == 0) return mid;
      else if (res == -1) high = mid - 1;
      else low = mid + 1;
    }
    return -1;
  }
};

int main() {
  Solution sol(6);

  int n = 10;

  cout << "Guessed Number: " << sol.guessNumber(n) << endl;

  return 0;
}
