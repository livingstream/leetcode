//============================================================================
// Decode Ways
// A message containing letters from A-Z is being encoded to numbers using
// the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of
// ways to decode it.
//
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.
// TODO improve performance to pass large test cases
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodingsHelper(string s) {
        int N = s.size();
        if (N == 0) return 0;
        if (N == 1) return (s[0] == '0') ? 0 : 1;
        if (N == 2) {
            if (s[0] == '0') return 0;
            if (s[1] == '0') return (s[0] <= '2') ? 1 : 0;
            if (s[0] <= '2' && s[1] <= '6') return 2;
            return 1;
        }
        if (s[0] == '0') return 0;
        if (s[1] == '0') {
            if (s[0] <= '2') return numDecodingsHelper(s.substr(2, N-2));
            return 0;
        }
        if (s[0] <= '2' && s[1] <= '6')
            return numDecodingsHelper(s.substr(1, N-1))
                    + numDecodingsHelper(s.substr(2, N-2));
        return numDecodingsHelper(s.substr(1, N-1));
    }

    int numDecodings(string s) {
        return numDecodingsHelper(s);
    }
};

int main() {
    return 0;
}
