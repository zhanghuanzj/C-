class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0,result = INT_MIN;
        for(int i=0;i<n;++i){
            if(sum<=0){
                sum = A[i];
            }else{
                sum += A[i];
            }
            result = max(result,sum);
        }
        return result;
    }
};