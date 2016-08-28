class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int result = num[0]+num[1]+num[3];
        for(int i=0;i<num.size();++i){
            int j = i+1,k = num.size()-1;
            while(j<k){
                if( abs(result-target) > abs(num[i]+num[j]+num[k]-target) ){
                    result = num[i]+num[j]+num[k];
                }
                if(num[i]+num[j]+num[k]>target){
                    --k;
                }else if(num[i]+num[j]+num[k]<target){
                    ++j;
                }else{
                    return target;
                }
            }
        }
        return result;
    }
};