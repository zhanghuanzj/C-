class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int n = matrix.size(),m = matrix.front().size();
        int x = 0,y = m-1;
        while(x<n&&y>=0){
            if(matrix[x][y]==target){
                return true;
            }else if(matrix[x][y]>target){
                --y;
            }else{
                ++x;
            }
        }
        return false;
    }
};