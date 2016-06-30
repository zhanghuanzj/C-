class Transform {
public:
    int calcCost(int A, int B) {
        int count = 0;
        int C = A^B;
        while(C)
        {
        	C = C&(C-1);
        	++count;
        }
        return count;
    }
};