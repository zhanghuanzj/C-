class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=0) return 0;
        int preIndex = 0;
        for(int i=1;i<n;++i){
            if(A[i]!=A[preIndex]){
                A[++preIndex] = A[i];
            }
        }
        return preIndex+1;
    }
};