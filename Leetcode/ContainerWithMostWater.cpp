class Solution {
public:
    int maxArea(vector<int> &height) {
        int result = 0;
        int left=0,right=height.size()-1;
        while(left<right){
            int h = min(height[left],height[right]);
            result = max(result,h*(right-left));
            while(left<right && height[left]<=h) ++left;
            while(left<right && height[right]<=h) --right;
        }
        return result;
    }
};