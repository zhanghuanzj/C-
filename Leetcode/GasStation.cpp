class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        vector<int> record(2*n);
        for(int i=0;i<n;++i){
            record[i] = record[n+i] = gas[i]-cost[i];
        }
        int start = 0;
        int sum = 0;
        for(int i=0;i<2*n;++i){
            if(sum<=0){
                start = i;
                sum = record[i];
            }else{
                sum += record[i];
            } 
            if(sum>=0&&i-start+1==n){
                return start;
            }
        }
        return -1;
    }
};