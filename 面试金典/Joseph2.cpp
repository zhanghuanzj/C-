class Joseph {
public:
	int getResult(int n) {
		list<int> linklist;
		for(int i=1;i<=n;++i){
			linklist.push_back(i);
		}
		auto cur = linklist.begin();
		int count = 1;
		int size = 3;
		while(linklist.size()>1){
			if (cur==linklist.end())
			{
				linklist.push_front(linklist.back());
				linklist.erase(--linklist.end());
				cur = linklist.begin();
				count = 1;
				++size;
			}
			if (count>=2){
				auto temp = cur++;
				linklist.erase(temp);
			}
			else{
				++cur;
			}
			count = (count+1)%size;
			count = count==0?1:count;
		}
		return linklist.front();
	}
};