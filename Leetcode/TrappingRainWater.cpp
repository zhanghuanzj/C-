class Solution {
public:
    int trap(int A[], int n) {
        int maxIndex = 0;
        for(int i=1;i<n;++i){
            if(A[i]>A[maxIndex]) maxIndex = i;
        }
        int water = 0,left = 0,right = 0;
        for(int i=0;i<maxIndex;++i){
            if(left<A[i]) left = A[i];
            else water += left-A[i];
        }
        for(int i=n-1;i>maxIndex;--i){
            if(right<A[i]) right = A[i];
            else water += right-A[i];
        }
        return water;
    }
};