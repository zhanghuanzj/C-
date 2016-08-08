class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		map<int,int> record;
		int result = 0;
		for (int i=0;i<num.size();++i)
		{
			if (!record.count(num[i]))
			{
				int left = record.count(num[i]-1)?record[num[i]-1]:0;
				int right = record.count(num[i]+1)?record[num[i]+1]:0;
				int cur = left+right+1;
				record.insert(make_pair(num[i],cur));
				record[num[i]-left] = cur;
				record[num[i]+right] = cur;
				result = max(result,cur);
			}
		}
		return result;
	}
};