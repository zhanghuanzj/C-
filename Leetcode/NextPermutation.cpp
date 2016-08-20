class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<=1) return;
        int i = num.size()-1;
        while(i>0 && num[i]<=num[i-1]) --i;
        if(i==0) {                           //5,4,3,2,1
            reverse(num.begin(),num.end());
        }else{
            int j = num.size()-1;
            while(num[j]<=num[i-1]) --j;
            swap(num[j],num[i-1]);
            reverse(num.begin()+i,num.end());
        }
    }
};