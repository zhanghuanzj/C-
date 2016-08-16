class Solution {
public:
    int climbStairs(int n) {
        if(n<1) return 0;
        if(n==1||n==2) return n;
        int x = 1,y = 2;
        int result = 0;
        for(int i=3;i<=n;++i){
            result = x+y;
            x = y;
            y = result;
        }
        return result;
    }
};