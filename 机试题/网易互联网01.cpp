#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		vector<int> cow(n);
		int avg = 0;
		for(int i=0;i<n;++i){
			cin>>cow[i];
			avg += cow[i];
		}
		if(avg%n!=0){
			cout<<-1<<endl;
			continue;
		}
		avg = avg/n;
		int count = 0;
		bool flag = false;
		for(auto e : cow){
			if(abs(e-avg)%2!=0){
				flag = true;
				break;
			}
			if(e>avg){
				count += (e-avg)/2;
			}
		}
		if(flag){
			cout<<-1<<endl;
		}else{
			cout<<count<<endl;
		}
	}
}