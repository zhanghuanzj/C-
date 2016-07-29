class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        int result = 0;
        vector<int> vec(n);
        for(int i=0;i<n;++i){
            fill(vec.begin(),vec.end(),0);
            for(int j=i;j<n;++j){
                for(int k=0;k<n;++k){
                    vec[k] += mat[j][k];
                }
                result = max(result,maxsum(vec));
            }
        }
        return result;
    }
private:
    int maxsum(vector<int>& vec){
        int sum = 0;
        int temp = 0;
        for(int i=0;i<vec.size();++i){
            if(temp<=0){
                temp = vec[i];
            }else{
                temp += vec[i];
            }
            sum = max(sum,temp);
        }
        return sum;
    }
};