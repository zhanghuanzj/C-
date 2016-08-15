 class Solution {
 public:
     string minWindow(string S, string T) {
         string result;
         map<char,int> TM,SM;
         for (auto c : T) TM[c]++;
         int count = 0,left = 0;
         for (int right=0;right<S.size();++right){
             if (TM[S[right]]!=0){
                 SM[S[right]]++;
                 if (SM[S[right]]<=TM[S[right]]) ++count;
                 while (count==T.size()){
                     if(result.empty()||result.size()>right-left+1){
                         result = S.substr(left,right-left+1);
                     }
                     if (TM[S[left]]){
                         SM[S[left]]--;
                         if (SM[S[left]]<TM[S[left]]) count--;               
                     }
                     ++left;
                 }
             }
         }
         return result;
     }
 };