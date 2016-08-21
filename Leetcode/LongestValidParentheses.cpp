class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0,left = 0;
        stack<int> st;
        for(int i=0; i<s.size(); ++i){
            if(s[i]==')'&&left){
                while(!st.empty()){
                    int index = st.top();
                    st.pop();
                    if(s[index]=='('){
                        --left;
                        break;
                    }
                }
            }else{
                if(s[i]=='(') ++left;
                st.push(i);
            }
        }
        int size = s.size();
        while(!st.empty()){            //计算最大区间
            result = max(result,size-st.top()-1);
            size = st.top();
            st.pop();
        }
        result = max(result,size);  
        return result;
    }
};