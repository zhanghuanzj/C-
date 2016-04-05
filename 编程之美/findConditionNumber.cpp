#include <iostream>
#include <vector>
using namespace std;

long long findConditionNumber(long long var)
{
	if (var==0)
	{
		return var;
	}
	vector<long long> record(var);
	for (int i=0;;i++)
	{
		long long j = pow(10,i);        //10^i
		bool isUpdate = false;
		if (record[j%var]==0)
		{
			record[j%var]=j;
			isUpdate = true;
		}
		//update
		for (int k=0;k<var;++k)
		{
			//1.存在余数为k的变量记录 2.j>该记录 3.j与该记录相加所得的余数没有记录
			if (record[k]!=0&&j>record[k]&&record[(record[k]+j)%var]==0)   
			{
				isUpdate = true;
				record[(record[k]+j)%var] = record[k]+j;
			}
		}
		if (!isUpdate)
		{
			return -1;
		}
		//Find the condition number
		if (record[0]!=0)
		{
			return record[0]/var;
		}
	}
}

int main()
{
	long long v;
	while (cin>>v)
	{
		cout<<findConditionNumber(v)<<endl;
	}
}