//============================================================================
// Given two words word1 and word2, find the minimum number of steps required
// to convert word1 to word2. (each operation is counted as 1 step.)
//
// You have the following 3 operations permitted on a word:
//
// a) Insert a character
// b) Delete a character
// c) Replace a character
//============================================================================

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();
        vector<vector<int> > dp;
        for (int i = 0; i <= M; i++) {
            vector<int> row;
            for (int j = 0; j <= N; j++)
                row.push_back(-1);
            dp.push_back(row);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= M; i++) dp[i][0] = i;
        for (int j = 1; j <= N; j++) dp[0][j] = j;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (word1[i-1] != word2[j-1]));
            }
        }
        return dp[M][N];
    }
};

int main() {
    return 0;
}
