class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i=1;i<n;++i){
            int count = 1;
            char pre = result[0];
            string temp;
            for(int j=1;j<result.size();++j){
                if(result[j]!=pre){
                    temp = temp + to_string(count) + to_string(pre-'0');
                    count = 1;
                    pre = result[j];
                }else{
                    ++count;
                }
            }
            if(count) temp = temp + to_string(count) + to_string(pre-'0');
            result = temp;
        }
        return result;
    }
};