class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;++i){
            if(i==1){
                result.push_back(vector<int>(1,1));
            }else{
                vector<int> arr(i);
                for(int j=0;j<i;++j){
                    if(j==0){
                        arr[j] = result[i-2].front();
                    }else if(j==i-1){
                        arr[j] = result[i-2].back();
                    }else{
                        arr[j] = result[i-2][j-1]+result[i-2][j];
                    }
                }
                result.push_back(arr);
            }
        }
        return result;
    }
};