class Exchange {
public:
    int exchangeOddEven(int x) {
        return ((0xAAAAAAAA&x)>>1)|((0x55555555&x)<<1);
    }
};