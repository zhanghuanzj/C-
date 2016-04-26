#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s[9] = {"yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
	int n;
	while (cin>>n)
	{
		vector<int> v;
		while (n)
		{
			v.push_back(n%10);
			n /= 10;
		}
		for (int i=v.size()-1;i>=0;--i)
		{
			if (i==2)
			{
				cout<<s[v[i]-1]<<"bai";
			}
			else if (i==1&&v[1]==0&&v[0]==0)
			{
				break;
			}
			else if (i==1&&v[1]!=0&&v[0]==0)
			{
				if (v[i]==1&&v.size()<3)
				{
					cout<<"shi";
				}
				else
				{
					cout<<s[v[i]-1]<<"shi";
					break;
				}
				
			}
			else if(i==1&&v[1]==0&&v[0]!=0)
			{
				 cout<<"ling";
			}
			else if (i==1&&v[1]!=0&&v[0]!=0)
			{
				if (v[i]==1&&v.size()<3)
				{
					cout<<"shi";
				}
				else
				{
					cout<<s[v[i]-1]<<"shi";
				}
			}
			else 
			{
				cout<<s[v[i]-1];
			}
		}
		cout<<endl;
	}
	
}