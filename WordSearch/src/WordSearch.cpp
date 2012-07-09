//============================================================================
// Word Search
// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
// For example,
// Given board =
//
// [
//   ["ABCE"],
//   ["SFCS"],
//  ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.
//============================================================================

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool existHelper(vector<vector<char> > &board, int i, int j, string &word, int k) {
        if (k == word.size()) return true;
        int M = board.size();
        int N = board[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N) return false;
        if (visited[i][j] || board[i][j] != word[k]) return false;
        visited[i][j] = true;
        return existHelper(board, i - 1, j, word, k + 1)
                || existHelper(board, i + 1, j, word, k + 1)
                || existHelper(board, i, j - 1, word, k + 1)
                || existHelper(board, i, j + 1, word, k + 1);
    };

    bool visited[128][128];
    bool exist(vector<vector<char> > &board, string word) {
        int M = board.size();
        int N = board[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                memset(visited, false, sizeof(bool)*16384);
                if (existHelper(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
