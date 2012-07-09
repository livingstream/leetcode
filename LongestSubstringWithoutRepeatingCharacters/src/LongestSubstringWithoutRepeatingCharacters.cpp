//============================================================================
// Given a string, find the length of the longest substring without repeating
// characters. For example,
//
// the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the
// length of 1.
//============================================================================

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t res = 0;
        size_t i = 0, j = 0;
        bool visited[256] = { false };
        while (j < s.size()) {
            if (visited[(int)s[j]]) {
                res = max(res, j - i);
                while (s[i] != s[j]) visited[(int)s[i++]] = false;
                i++;
                j++;
            } else {
                visited[(int)s[j]] = true;
                j++;
            }
        }
        res = max(res, j - i);
        return res;
    }
};

int main() {
    return 0;
}
