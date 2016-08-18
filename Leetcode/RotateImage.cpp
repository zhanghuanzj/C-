class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        int n = matrix.size();
    	for(int i=0;i<n/2;++i){
            int m = n/2;
            if(n&1) ++m;
            for(int j=0;j<m;++j){
                int x=i,y=j;
                int var = matrix[i][j];
                for(int k=0;k<4;++k){
                    int temp = x;
                    x = y,y=n-temp-1;
                    swap(var,matrix[x][y]);
                }
            }
        }
    }
};