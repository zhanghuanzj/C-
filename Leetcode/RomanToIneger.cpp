class Solution {
public:
    int romanToInt(string s) {
        map<char,int> book;
        book['I']=1;
        book['V']=5;
        book['X']=10;
        book['L']=50;
        book['C']=100;
        book['D']=500;
        book['M']=1000;
        int result = 0;
        for(int i=0;i<s.size();++i){
            if(i>0 && book[s[i]]>book[s[i-1]]){
                result += book[s[i]]-2*book[s[i-1]];
            }else{
                result += book[s[i]];
            }
        }
        return result;
    }
};