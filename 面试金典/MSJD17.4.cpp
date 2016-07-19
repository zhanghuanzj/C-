class Max {
public:
    int getMax(int a, int b) {
        int c = (a-b)>>31;
        return a+c*(a-b);
    }
};