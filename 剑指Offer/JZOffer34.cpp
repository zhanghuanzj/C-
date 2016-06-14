class Solution {
public:
	int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
		vector<int> ugly;
		ugly.push_back(1);
		int index2=0,index3=0,index5=0;
		for (int i = 1; i < index; ++i)
		{
			int temp = Min(ugly[index2]*2,ugly[index3]*3,ugly[index5]*5);
			ugly.push_back(temp);
			//可能存在重复的如2*3,3*2,所以每次都得更新
			while(ugly[index2]*2<=temp) index2++;
			while(ugly[index3]*3<=temp) index3++;
			while(ugly[index5]*5<=temp) index5++;
		}
		return ugly.back();
	}
	int Min(int a,int b,int c)
	{
		int result = min(a,b);
		return min(result,c);
	}
};