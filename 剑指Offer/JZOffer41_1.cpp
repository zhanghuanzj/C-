class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		vector<int> result;
		int left = 0;
		int right = array.size()-1;
		while (left<right)
		{
			if (array[left]+array[right]==sum)
			{
				result.push_back(array[left]);
				result.push_back(array[right]);
                break;
			}
			else if (array[left]+array[right]<sum)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
		return result;
	}
};