//============================================================================
// Implement strStr().
//
// Returns a pointer to the first occurrence of needle in haystack,
// or null if needle is not part of haystack.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL || !*needle) return haystack;
        char *p1e = haystack, *p1 = haystack, *p2 = needle;
        while (*++p2) p1e++;
        while (*p1e) {
            char *p1b = p1;
            char *p2 = needle;
            while (*p1 && *p2 && *p1 == *p2) ++p1, ++p2;
            if (!*p2) return p1b;
            p1 = p1b + 1;
            p1e++;
        }
        return NULL;
    }
};

int main() {
    return 0;
}
