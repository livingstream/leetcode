//============================================================================
// Write a function to find the longest common prefix string amongst an array
// of strings.
//============================================================================

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int N = strs.size();
        if (N == 0) return "";
        if (N == 1) return strs[0];
        size_t i = 0;
        while (true) {
            if (strs[0].size() <= i) break;
            char c = strs[0][i];
            for (int k = 1; k < N; k++) {
                if (strs[k].size() <= i || strs[k][i] != c) return strs[k].substr(0, i);
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};

int main() {
    return 0;
}
