/**
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    
        int m = matrix[0].size();
        int row = 0,col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col]<target) {
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};
//if we stand at 1 and then if we go botoom or right both side increases so we cannot decide where should we go.
//same is the case if we stand at 30
//but if we stand at 15 or 18 we can decide which way to go and search thr target
//lets stand at 15 we see our target is 5 and it cannot be in the same column as that of 15 so we eleiminate thaty column.
//now wew stand at 11 --> eliminate column -->standing at 7--> eliminating col -->stand at 4-->eliminating row
//get the desired result
 */