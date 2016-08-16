 class Solution {
 public:
	 vector<string> fullJustify(vector<string> &words, int L) {
		 vector<string> result;
		 int pre = -1,count = 0,word = 0;
		 for(int i=0;i<words.size();++i){
			 if(pre==-1){
				 pre = i;
			 }
			 if(count+word+words[i].size()<=L){
				 count += words[i].size();
				 word++;
			 }else{
				 int pad,remain = 0;
				 if (word==1){
					 pad = L-count;
				 }else{
					 pad = (L-count)/(word-1);
					 remain = (L-count)%(word-1);
				 }
				 string line;
				 for(int j=pre;j<i;++j){
					 int remainPad = 0;
					 if (remain){
						 --remain;
						 remainPad = 1;
					 }
					 if(j<i-1){
						 line = line + words[j] + string(pad+remainPad,' ') ;
					 }else{
						 line = line + words[j];
					 }
				 }
				 --i;
				 pre = -1,count = 0,word = 0;
				 line = line + string(L-line.size(),' ');
				 result.push_back(line);
			 }
		 }
		 string last;
		 for(int i=pre;i<words.size();++i){
			 if (i==pre){
				 last = words[i];
			 }else{
				 last = last + " "+ words[i];
			 } 
		 }
		 last = last + string(L-last.size(),' ');
		 if(!last.empty()||L==0) result.push_back(last);
		 return result;
	 }
 };