class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0,right = n-1,cur = 0;
        while(cur<=right){
            if(A[cur]==0&&cur>=left) swap(A[left++],A[cur]);
            else if(A[cur]==2&&cur<=right) swap(A[right--],A[cur]);
            else ++cur;
        }
    }
};