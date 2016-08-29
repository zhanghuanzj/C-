class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
    bool solve(string s,string p,int si,int pi){
        if (pi==p.size()){
            return si==s.size();
        }
        if (p[pi+1]!='*'){
            return (p[pi]==s[si]||(p[pi]=='.'&&si<s.size()))&&solve(s,p,si+1,pi+1);
        }
        while (p[pi]==s[si]||(p[pi]=='.'&&si<s.size())){
            if (solve(s,p,si,pi+2)){
                return true;
            }
            ++si;
        }
        return solve(s,p,si,pi+2);
    }
};