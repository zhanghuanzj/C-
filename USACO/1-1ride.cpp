/*
ID: zhanghu14
PROG: ride
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string s1,s2;
    while (fin>>s1>>s2)
    {
        int sum1 = 1, sum2 = 1;
        for (auto c : s1)
        {
            sum1 = (sum1*(c-'A'+1))%47;
        }
        for (auto c : s2)
        {
            sum2 = (sum2*(c-'A'+1))%47;
        }
        if (sum1==sum2)
        {
            fout<<"GO"<<endl;
        }
        else
        {
            fout<<"STAY"<<endl;
        }
    }
}

 