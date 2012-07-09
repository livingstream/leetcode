//============================================================================
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//
//
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        if (n == 1) return res;
        for (int i = 1; i < n; i++) {
            ostringstream stream;
            size_t j = 0;
            while (j < res.size()) {
                char c = res[j++];
                size_t s = 1;
                while (j < res.size() && res[j] == c ) j++, s++;
                stream << s << c;
            }
            res = stream.str();
        }
        return res;
    }
};

int main() {
    return 0;
}
