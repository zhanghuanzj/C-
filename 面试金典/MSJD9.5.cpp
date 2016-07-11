
class Permutation {
public:
	vector<string> getPermutation(string A) {
		vector<string> result;
		sort(A.begin(),A.end());
		result.push_back(string("")+A[0]);
		int index = 1;
		for(int i=1;i<A.size();++i,++index){
			vector<string> temp;
			for(auto s:result){
				s.insert(s.begin(),A[i]);
				temp.push_back(s);
			}
			for(auto s:result){
				for(int j=1;j<=index;++j){
					string t = s;
					t.insert(t.begin()+j,A[i]);
					temp.push_back(t);
				}
			}
			result = temp;
            sort(result.begin(),result.end(),greater<string>());
		}
		return result;
	}
};
/*	vector<string> getPermutation(string A) {
		vector<string> result;
		sort(A.begin(),A.end(),greater<char>());
		string s=A;
		do{
			A = s;
			result.push_back(A);
			s = nextPermutation(A);
		}while(s!=A);
		return result;
	}

	string nextPermutation(string s){
		int index = 0;
		for(int j=s.size()-1;j>0;--j){
			if(s[j-1]>s[j]) {
				index = j-1;
				break;
			}
		} 
		for(int i=s.size()-1;i>index;--i){
			if(s[i]<s[index]){
				swap(s[i],s[index]);
				reverse(s.begin()+index+1,s.end());
				break;
			}      
		}
		return s;
	}*/