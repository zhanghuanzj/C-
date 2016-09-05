/*
ID: zhanghu14
PROG: palsquare
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
int main()
{
    const string path = "palsquare";
    ifstream fin(path+".in");
    ofstream fout(path+".out");
    
    int b;
    while (fin>>b)
    {
        for (int i=1;i<=300;i++) {
            string value = getValue(i*i,b);
            string rvalue = value;
            reverse(begin(rvalue),end(rvalue));
            if (value==rvalue){
                fout<<getValue(i,b)<<" "<<value<<endl;
            }
        }
    }
}


