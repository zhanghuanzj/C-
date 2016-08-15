class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=0) return 0;
        int preIndex = 0,remain = 1;
        for(int i=1;i<n;++i){
            if(A[preIndex]!=A[i]){
                remain = 1;
                A[++preIndex] = A[i];
            }else{
                if(remain==1){
                    --remain;
                    A[++preIndex] = A[i];
                }
            }
        }
        return preIndex+1;
    }
};