#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> generateNext(string s)
{
	vector<int> next;
	next.push_back(-1);           //第一位为标记位
	int j= -1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (j==-1||s[i]==s[j])    //j为第一个未匹配上标志
		{
			++i,++j;
			next.push_back(j);
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}

int kmp(string s1,string s2)
{
	vector<int> next = generateNext(s2);
	int i=0,j=0;
	int size1 = s1.size()-s2.size();
	int size2 = s2.size();
	while(i<=size1&&j<size2)
	{
		if (j==-1||s1[i]==s2[j]) //第一个未匹配上或字串相匹
		{
			++i,++j;
		}
		else
		{
			j = next[j];
		}
	}
	return j==s2.size()?i-j:-1;
}
int main()
{
	string s1,s2;
	while (cin>>s1>>s2)
	{
		cout<<kmp(s1,s2)<<endl;
	}
}