class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c=='(' || c=='{' || c=='['){
                st.push_back(c);
            }else if(c==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(c=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};