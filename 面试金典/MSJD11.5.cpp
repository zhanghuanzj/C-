class Finder {
public:
	int findString(vector<string> str, int n, string x) {
		return solve(str,0,n-1,x);
	}

	int solve(vector<string> str,int left,int right,string x){
		while(left<right){
			int mid = (left+right)/2;
			if(str[mid]==""){
				int lresult = solve(str,left,mid-1,x);
				if(lresult!=-1) return lresult;
				int rresult = solve(str,mid+1,right,x);
				if(rresult!=-1) return rresult;
				return -1;
			}
			else{
				if(str[mid]>x){
					right = mid-1;
				}
				else if(str[mid]==x){
					return mid;
				}
				else{
					left = mid+1;
				}
			}
		}
		if(str[left]==x) return left;
		return -1;
	}
};