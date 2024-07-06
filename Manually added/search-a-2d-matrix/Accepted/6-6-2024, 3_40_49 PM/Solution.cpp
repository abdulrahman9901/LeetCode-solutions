// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0 , col = 0 , m = matrix.size() , n=matrix[0].size();
        int left = 0 , right = n ,up = 0, down = m ,mid ;
        while(up < down){
            mid = (up + down ) /2 ;
            if(target > matrix[mid][0]){
                if(target <=matrix[mid][n-1]){
                row = mid;
                break;
                }
             if(up == mid)
                break;
            up = mid;
            }else if (target < matrix[mid][0]){
                if(up == mid)
                    break;
                down = mid;
            }else{
                return true;
            }
        }
        cout<<row<<endl;
        while(left < right){
            mid = (left + right)/2; 
            if(matrix[row][mid] == target ){
                return true;
            }else if (matrix[row][mid] < target) {
                if(left == mid)
                    break;
                left = mid;
            }else {
                if(right == mid)
                    break;
                right = mid;
            }
        }
        return false;
    }
};