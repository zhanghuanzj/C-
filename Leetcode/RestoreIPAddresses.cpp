class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		solve(s,0,1,"",result);
		return result;
	}
	void solve(const string &s,int index,int depth,string ip,vector<string> &result){
		if(depth==4){
			if (s.size()-index<=3)
			{
				string sub = s.substr(index);
				if (sub[0]=='0'&&sub.size()>1)
				{
					return;
				}
				int val = stoi(sub);
				if (val<256)
				{
					result.push_back(ip+sub);
				}
			}
		}
		else
		{
			for (int i=1;i<=3&&index+i<s.size();++i)
			{
				string sub = s.substr(index,i);
				if (sub[0]=='0'&&sub.size()>1)
				{
					break;
				}
				int val = stoi(sub);
				if (val<256)
				{
					solve(s,index+i,depth+1,ip+sub+".",result);
				}
			}
		}
	}
};