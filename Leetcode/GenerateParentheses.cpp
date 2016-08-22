class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(result,"",n,n);
        return result;
    }
    void solve(vector<string> &result,string s,int remainLeft,int remainRight){
        if(remainLeft==0 && remainRight==0){
            result.push_back(s);
        }
        if(remainLeft){
            solve(result,s+"(",remainLeft-1,remainRight);
        }
        if(remainRight && remainLeft<remainRight){
            solve(result,s+")",remainLeft,remainRight-1);
        }
    }
};