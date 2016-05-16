class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        int op = 1;
        int sum = 0;
        for(int i=0;i<str.size();++i)
        {
            if(i==0&&(str[i]=='-'||str[i]=='+')){
                if(str[i]=='-')
                	op = -1;
                continue;
            }
            if(str[i]>='0'&&str[i]<='9'){
                sum = sum*10+str[i]-'0';
            }  
            else{
                return 0;
            }
        }
        return op*sum;
    }
};