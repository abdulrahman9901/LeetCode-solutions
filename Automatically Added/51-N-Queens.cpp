#include <iostream>
#include <vector>
#include <string>

class Solution {
    int n;
    std::vector<bool> rows, cols, mainDiagonals, antiDiagonals;
   
    // Depth-first search function to find all solutions
    void dfs(std::vector<std::vector<std::string>>& results, int r, std::vector<std::string>& result) {
        if (r == n) {
            results.push_back(result);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (!rows[r] && !cols[c] && !mainDiagonals[r - c + (n - 1)] && !antiDiagonals[r + c]) {
                result[r][c] = 'Q';
                rows[r] = cols[c] = mainDiagonals[r - c + (n - 1)] = antiDiagonals[r + c] = true;
                dfs(results, r + 1, result);
                result[r][c] = '.';
                rows[r] = cols[c] = mainDiagonals[r - c + (n - 1)] = antiDiagonals[r + c] = false;
            }
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        this->n = n;
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> result(n, std::string(n, '.'));
        rows = cols = std::vector<bool>(n, false);
        mainDiagonals = antiDiagonals = std::vector<bool>(2 * n - 1, false);
        dfs(results, 0, result);
        return results;
    }
};
