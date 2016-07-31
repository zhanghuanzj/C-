class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> record;
        for(auto e : tokens){
            if(e=="+" || e=="-" || e=="*" || e=="/"){
                int x = record.top();
                record.pop();
                int y = record.top();
                record.pop();
                record.push(cal(x,y,e));
            }else{
                record.push(stoi(e));
            }
        }
        return record.top();
    }
    
    int cal(int x,int y,string op){
        if(op=="*"){
            return x*y;
        }else if(op=="+"){
            return x+y;
        }else if(op=="-"){
            return y-x;
        }else if(op=="/"){
            return y/x;
        }
        return 0;
    }
};