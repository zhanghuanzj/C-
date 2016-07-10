class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        return solve(A,0,n-1);
    }
    
    bool solve(vector<int> &A,int left,int right){
        if(left>right) return false;
        int mid = (left+right)/2;
        if(A[mid]==mid) return true;
        return solve(A,left,min(mid-1,A[mid]))||solve(A,max(mid+1,A[mid]),right);
    }
};
