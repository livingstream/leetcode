//============================================================================
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int maxi = 0;
        int maxl = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int start = i - j;
                int end = i + 1;
                while (start >= 0 && end < n && s[start] == s[end])
                    start--, end++;
                start++, end--;
                int len = end - start + 1;
                if (len > maxl) maxi = start, maxl = len;
            }
        }
        return s.substr(maxi, maxl);
    }
};

int main() {
    return 0;
}
