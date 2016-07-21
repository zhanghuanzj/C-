class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        int result = 0, temp = 0;
        for(int i=0; i<n; ++i){
            if(temp<=0){
                temp = A[i];
            }
            else temp += A[i];
            result = max(result,temp);
        }
        return result;
    }
};