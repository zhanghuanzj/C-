class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	int left = 0;
	int right = rotateArray.size()-1;
	while (left<right)
	{
		while (left<rotateArray.size()-1&&left<right&&rotateArray[left]==rotateArray[left+1])
		{
			left++;
		}
		while (right>=1&&left<right&&(rotateArray[right]==rotateArray[right-1]||rotateArray[left]==rotateArray[right]))
		{
			right--;
		}
		int mid = left+(right-left)/2;
		if (rotateArray[left]<=rotateArray[right])
		{
			return rotateArray[left];
		}
		else
		{
			if (rotateArray[mid]>=rotateArray[left])
			{
				left = mid+1;
			}
			else
			{
				right = mid;
			}
		}
	}
	if(left==right)
		return rotateArray[left];
	return 0;
    }
};