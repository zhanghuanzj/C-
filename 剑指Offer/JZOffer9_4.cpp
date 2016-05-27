class Solution {
public:
    int rectCover(int number) {
    	if (number<=2)
    	{
    		return number;
    	}
    	int pre = 1, post = 2;
    	for (int i = 3; i <= number; ++i)
    	{
    		post = pre +post;
    		pre = post-pre;
    	}
    	return post;
    }
};