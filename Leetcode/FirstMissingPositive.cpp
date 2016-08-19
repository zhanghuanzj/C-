class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int index = 0 ,n = nums.size();
        while(index<n){
            if(nums[index]>0&&nums[index]<n&&nums[nums[index]-1]!=nums[index]){
                swap(nums[index],nums[nums[index]-1]);
            }else{
                ++index;
            }
        }
        index = 0;
        while(index<n && nums[index]==index+1){
            ++index;
        }
        return index+1;
    }
};
