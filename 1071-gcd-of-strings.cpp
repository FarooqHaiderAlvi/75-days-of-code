#include <iostream>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
  
    int length1 = str1.length();
    int length2 = str2.length();

    // Ensure that length1 is always greater than or equal to length2 for GCD calculation
    if (length1 < length2) {
      swap(length1, length2); // Swap lengths if necessary
      swap(str1, str2); // Swap the strings as well
    }

    // Calculate the GCD of the lengths of the two strings using Euclidean algorithm
    int remainder = 0;
    while (true) {
      remainder = length1 % length2; 
      if (remainder == 0) 
        break;
      length1 = length2;
      length2 = remainder;
    }

    int gcdLength = length2;
    string candidateGCD = str1.substr(0, gcdLength);

    //check if candidataGCD completely divides str1 and str2
    int i = 0;
    while (i < str1.length() || i < str2.length()) {
      if (i < str1.length()) {
        if (str1[i] != candidateGCD[i % gcdLength])
          return "";
      }
      if (i < str2.length()) {
        if (str2[i] != candidateGCD[i % gcdLength])
          return "";
      }
      i++;
    }

    return candidateGCD;
  }
};


int main() {

  Solution obj;
  cout << (obj.gcdOfStrings("ABABABAB", "ABAB"));

}