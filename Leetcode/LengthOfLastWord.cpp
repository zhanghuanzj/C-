class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = 0,pre = 0,cur = 0;
		while(s[cur]!='\0'){
			if(s[cur]==' '){
				if (cur-pre){
					len = cur-pre;
				}
				pre = cur+1;
			}
			++cur;
		}
		if (cur-pre){
			len = cur-pre;
		}
		return len;
	}
};