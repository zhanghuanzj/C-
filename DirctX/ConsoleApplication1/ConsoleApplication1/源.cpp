#include <iostream>
#include <vector>
using namespace std;
int main()
{
	unsigned long long n,m;
	unsigned long long mod = 0x100000000;
	unsigned long long modL = 0x00000000ffffffff;
	while (cin>>n>>m)
	{
		vector<long long> record;
		//record.push_back(m);
		int index = 0;
		unsigned long long result = 0;
		unsigned long long pre = 1;
		for ( int i=1;i<=n;++i)
		{

			if (i&1)
			{
				pre =(pre*m)%mod;
			}
			else
			{
				
				cout<<"L:"<<pre*m<<endl;
				cout<<"R:"<<record[index]<<endl;
				cout<<pre*m-record[index]<<endl;
				pre = ((pre*m)-record[index++]+mod)%mod;
			}
			result = (result+pre)%mod;
			if (pre==0)
			{
				pre = mod;
			}
			record.push_back(pre);
		}
		cout<<result<<endl;
	}

}