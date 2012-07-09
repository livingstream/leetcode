//============================================================================
// N-Queens II
// Follow up for N-Queens problem.
//
// Now, instead outputting board configurations, return the total number of
// distinct solutions.
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isSafe(int hist[], int i, int j, int col) {
        return (hist[j] != i && abs(hist[j] - i) != col - j);
    }

    void totalNQueensHelper(int hist[], int n, int col, int &count) {
       if (col == n) count++;
       for (int i = 0, j = 0; i < n; i++) {
           for (j = 0; j < col && isSafe(hist, i, j, col); j++);
           if (j < col) continue;
           hist[col] = i;
           totalNQueensHelper(hist, n, col + 1, count);
       }
    }

    int totalNQueens(int n) {
        int count = 0;
        int hist[n];
        totalNQueensHelper(hist, n, 0, count);
        return count;
    }
};

int main() {
	return 0;
}
