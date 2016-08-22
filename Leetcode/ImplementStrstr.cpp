class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		int size1 = strlen(haystack);
		int size2 = strlen(needle);
		vector<int> next = getNext(needle,size2);
		int i=0,j=0;
		while(i<size1 && j<size2){
			if(j==-1 || haystack[i]==needle[j]){
				++i,++j;
			}else{
				j = next[j];
			}
		}
		return j==size2?(haystack+i-j):nullptr;
	}

	vector<int> getNext(char *needle,int size2){
		vector<int> next(size2,-1);
		for(int i=0,j=-1;i<size2-1;){
			if(j==-1 || needle[i]==needle[j]){
				++j;
				next[++i] = j;
			}else{
				j = next[j];
			}
		}
		return next;
	}
};