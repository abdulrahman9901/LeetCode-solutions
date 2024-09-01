class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;

        int startRow = 0, endRow = m - 1;
        int startCol = 0, endCol = n - 1;

        while (startRow <= endRow && startCol <= endCol) {

            for (int j = startCol; j <= endCol; j++) {
                res.push_back(matrix[startRow][j]);
            }
            startRow++; 

            
            for (int i = startRow; i <= endRow; i++) {
                res.push_back(matrix[i][endCol]);
            }
            endCol--; 

            
            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol; j--) {
                    res.push_back(matrix[endRow][j]);
                }
                endRow--; 
            }

            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    res.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }

        return res; // Return the result vector
    }
};
