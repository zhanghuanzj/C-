class UnusualAdd {
public:
    int addAB(int A, int B) {
        int result = A;
        while(B){
            result = result^B;
            B = (A&B)<<1;
            A = result;
        }
        return result;
    }
};