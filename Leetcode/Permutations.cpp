class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        sort(num.begin(),num.end());
        result.push_back(num);
        while(!permutation(num))
            result.push_back(num);
        return result;
    }
    bool permutation(vector<int> &num){
        int i = num.size()-1;
        while(i>0 && num[i]<num[i-1]) --i;
        if(i==0) return true;
        int j = num.size()-1;
        while(num[j]<num[i-1]) --j;
        swap(num[j],num[i-1]);
        reverse(num.begin()+i,num.end());
        return false;
    }
};