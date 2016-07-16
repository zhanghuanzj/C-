class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        vector<int> result;
        int i=0,j=m-1;
        while(i<n&&j>=0){
            if(mat[i][j]>x) --j;
            else if(mat[i][j]<x) ++i;
            else{
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
        return result;
    }
};