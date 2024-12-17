#include <iostream>
using namespace std;

class Solution {
public:
  
    string mergeAlternately(string word1, string word2) {

        // Initialize two indices i and j to keep track of the position in word1 and word2
        int i = 0, j = 0;
        
        // Create an empty string result to store the merged string
        string result = "";
        
        // This loop will alternate between adding characters from word1 and word2
        while (i < word1.length() && j < word2.length()) {
            // Add the character from word1 at index i
            result += word1[i];
            i++; 
            // Add the character from word2 at index j
            result += word2[j];
            j++; 
        }
        
        // If there are any remaining characters in word1, add them to result.
        while (i < word1.length()) {
            result += word1[i];
            i++; 
        }

        // Similarly, if there are remaining characters in word2, add them to result.
        while (j < word2.length()) {
            result += word2[j];
            j++;
        }
        
        return result;
    }
};

// Main function to demonstrate the mergeAlternately function
int main()
{
    Solution obj;
    cout << obj.mergeAlternately("abc", "pqr");

    return 0;
}
