class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for(int i=0;i<32;++i){
            int count = 0;
            for(int j=0;j<n;++j){
                count += (1<<i)&A[j]?1:0;
            }
            result += (count%3)<<i;
        }
        return result;
    }
};