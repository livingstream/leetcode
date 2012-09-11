//============================================================================
// Interleaving String
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleaveHelper(s1.c_str(), s2.c_str(), s3.c_str());
    }

    bool isInterleaveHelper(const char *s1,const char *s2,const char *s3) {
        if(*s1 == '\0' && *s2 == '\0' && *s3 == '\0') return true;
        if (*s3 == '\0') return false;
        if (*s1 == '\0' && *s2 == '\0') return false;

        return ((*s1==*s3 && isInterleaveHelper(s1+1, s2, s3+1)) ||
                (*s2==*s3 && isInterleaveHelper(s1, s2+1, s3+1)));
    }
};

int main() {
    Solution sol;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}
