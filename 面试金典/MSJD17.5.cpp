class Result {
public:
	vector<int> calcResult(string A, string guess) {
		set<int> fake;
		multiset<int> right;
		for(int i=0;i<4;++i){
			if(guess[i]==A[i]){
                right.insert(i);
            }
		}
        for(int i=0;i<4;++i){
            if(right.find(i)==right.end()){
                for(int j=0;j<4;++j){
                    if(guess[i]==A[j]&&(right.find(j)==right.end())&&(fake.find(j)==fake.end())){
                        fake.insert(j);
                        break;
                    }
                }
            }
        }
		vector<int> result;
		result.push_back(right.size());
		result.push_back(fake.size());
		return result;
	}
};