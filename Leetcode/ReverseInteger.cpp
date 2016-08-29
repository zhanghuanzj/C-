class Solution {
public:
    int reverse(int x) {
        long var = 0, n = x;
        int sign = 1;
        if(n<0){
            n = -n;
            sign = -1;
        }
        while(n){
            var = var*10 + n%10;
            n /= 10;
        }
        if(var*sign>=INT_MAX || var*sign<=INT_MIN){
            return 0;
        }
        return var*sign;
    }
};