class Solution {
public:
    int jumpFloor(int number) {
        if (number<=2)
        {
        	return number;
        }
        int pre=1,post=2,result;
        for (int i = 3; i <= number; ++i)
        {
        	result = pre+post;
        	pre = post;
        	post = result;
        }
        return result;
    }
};