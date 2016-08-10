class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int>> arr = triangle;
        for(int i=1;i<arr.size();++i){
            for(int j=0;j<arr[i].size();++j){
                if(j==0) {
                    arr[i][j] += arr[i-1].front();
                }else if(j==arr[i].size()-1){
                    arr[i][j] += arr[i-1].back();
                }else{
                    arr[i][j] += mini(arr[i-1][j-1],arr[i-1][j]);
                }
            }
        }
        int mini = INT_MAX;
        for(int i=0;i<arr.back().size();++i){
            mini = min(mini,arr.back()[i]);
        }
        return mini;
    }
};