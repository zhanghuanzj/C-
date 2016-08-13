class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()||s[0]=='0')
        {
            return 0;
        }
        vector<int> dp(s.size()+1,0);
        dp[0] = dp[1] = 1;
        for (int i=2;i<=s.size();++i)
        {
            int pre = s[i-2]-'0';
            int cur = s[i-1]-'0';
            if (cur==0) //10,20，必须组合
            {
                if ((pre==1||pre==2))
                {
                    dp[i] = dp[i-2];
                }
            }
            else
            {
                if (pre==1||(pre==2&&cur<=6)) //1X,2X，可分可组
                {
                    dp[i] = dp[i-1]+dp[i-2];
                }
                else  //X 必须分开
                {
                   dp[i] = dp[i-1]; 
                }
            }
        }
        return dp[s.size()];
    }
};