class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        vector<vector<int>> result;
        sort(A.begin(),A.end());
        int size = pow(2,n);
        for(int i=size-1;i>0;--i){
            vector<int> temp;
            int k = i;
            int index = 0;
            while(k){
                if(k&1) temp.push_back(A[index]);
                k >>= 1;
                ++index;
            }
            reverse(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }
};