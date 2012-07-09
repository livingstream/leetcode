//============================================================================
// Given an array of strings, return all groups of strings that are anagrams.
//
// Note: All inputs will be in lower-case.
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > dict;
        for (size_t i = 0; i < strs.size(); i++) {
            string copy(strs[i]);
            sort(copy.begin(), copy.end());
            dict[copy].push_back(strs[i]);
        }
        vector<string> res;
        map<string, vector<string> >::iterator it = dict.begin();
        while (it != dict.end()) {
            size_t n = it->second.size();
            if (n > 1) {
                for (size_t i = 0; i < n; i++)
                    res.push_back(it->second[i]);
            }
            it++;
        }
        return res;
    }
};

int main() {
    return 0;
}
