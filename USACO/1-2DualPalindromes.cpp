/*
ID: zhanghu14
PROG: dualpal
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

char base[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
string getValue(int num,int b){
	string value;
	do 
	{
		value = base[num%b] + value;
		num /= b;
	} while (num);
	return value;
}
bool isPalindromes(string num){
	string rvalue = num;
	reverse(begin(rvalue),end(rvalue));
	return rvalue == num;
}
int main()
{
	const string path = "dualpal";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	
	int n,s;
	while (fin>>n>>s)
	{
		int count = 0;
		for (int i=s+1;count<n;++i) {
			int base = 0;
			for (int b=2;b<=10&&base<2;++b) {
				string value = getValue(i,b);
				if (isPalindromes(value)){
					++base;
				}
			}
			if (base==2){
				++count;
				fout<<i<<endl;
			}	
		}
	}
}


