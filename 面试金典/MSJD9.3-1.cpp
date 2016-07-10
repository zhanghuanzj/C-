class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        int left = 0;
        int right = n-1;
        int mid = 0;
        while(left<right){
            mid = (right+left)/2;
            if(A[mid]==mid) return true;
            else if(A[mid]<mid){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return A[left]==left;
    }
};