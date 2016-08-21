class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor==0 || (dividend==INT_MIN&&divisor==-1))
			return INT_MAX;
		int sign = ((dividend<0)^(divisor<0))?-1:1;
		long long a = dividend;
		long long b = divisor;
		a = a>0?a:-a;
		b = b>0?b:-b;
		long long result = 0;
		while(a>=b){
			int count = 1;
			long long d = b;
			while(a>=(d<<1)){
				count <<= 1;
				d <<= 1;
			}
			a -= d;
			result += count;
		}
		return sign==1?result:-result;
	}
};