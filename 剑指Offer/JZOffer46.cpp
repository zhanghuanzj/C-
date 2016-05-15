typedef int (*fun)(int);
class Solution {
public:
	int Sum_Solution(int n) {
		return solve(n);
	}
	static int solve(int n)
	{
		fun f[2] = {teminator,solve};
		return f[!!n](n-1)+n;
	}
	static int teminator(int n)
	{
		return 0;
	}
};