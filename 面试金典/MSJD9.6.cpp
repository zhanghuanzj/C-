class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> s;
        for(auto c:A){
            if(c==')'){
                while(true){
                    if(s.empty()) return false;
                    if(s.top()=='('){
                        s.pop();
                        break;
                    }
                    s.pop();
                }
            }
            else{
                s.push(c);
            }
        }
        return s.empty();
    }
};