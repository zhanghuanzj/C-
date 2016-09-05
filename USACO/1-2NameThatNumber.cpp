/*
ID: zhanghu14
PROG: namenum
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

char dict[] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
string getValue(string s){
	string result = "";
	for (int i=0;i<s.size();i++) {
		result += dict[s[i]-'A'];
	}
	return result;
}
int main()
{
	const string path = "namenum";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	ifstream dict("dict.txt");
	map<string,string> hash;
	string s;
	while (dict>>s){
		hash[s] = getValue(s);
	}

	string n;
	while (fin>>n)
	{
		bool isValid = false;
		for (auto p : hash) {
			if (p.second==n){
				isValid = true;
				fout<<p.first<<endl;
			}
		}
		if (!isValid){
			fout<<"NONE"<<endl;
		}
	}
}


