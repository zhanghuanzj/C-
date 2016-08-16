 class Solution {
 public:
	 int sqrt(int x) {
		 if(x==0) return 0;
		 double x0=x,x1;
		 do 
		 {
			 x1 = x0;
			 x0 = (x/x0+x0)/2;
		 } while (abs(x0-x1)>0.1);
		 return x0;
	 }
 };