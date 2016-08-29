class Solution {
public:
    int atoi(const char *str) {
        long result = 0;
        int sign = 1;
        while(*str!='\0'&&*str==' ') ++str;
       	if(*str=='-'){
            sign = -1;
        }
        if(*str=='-'||*str=='+') ++str;
        while(*str!='\0'){
            if(*str<='9'&&*str>='0'){
                result = result*10+(*str-'0');
                if(result*sign>=INT_MAX||result*sign<=INT_MIN){
                    return sign==1?INT_MAX:INT_MIN;
                }
            }else{
                break;
            }
            ++str;
        }
        return result*sign;
    }
};