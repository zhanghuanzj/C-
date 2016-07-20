class Factor {
public:
    int getFactorSuffixZero(int n) {
        int count = 0;
        while(n){
            count += n/5;
            n /= 5;
        }
        return count;
    }
};