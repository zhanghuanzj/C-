#include<iostream>  

using namespace std;  

int commDivisor(int n,int m)
{
  if (n%m==0)
  {
    return m;
  }
  else
  {
    return commDivisor(m,n%m);
  }
}
int main()
{
  int c,n,b;
  while (cin>>n>>c)
  {
    while (n--)
    {
      cin>>b;
      if (b<=c)
      {
        c += b;
      }
      else
      {
        c += commDivisor(c,b);
      }
    }
    cout<<c<<endl;
  }
  
  return 0;
}