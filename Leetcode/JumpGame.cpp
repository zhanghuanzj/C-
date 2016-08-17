class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0,index = 0;
        while(i<=index){
            index = max(index,i+A[i]);
            if(index >= n-1) return true;
            ++i;
        }
        return false;
    }
};