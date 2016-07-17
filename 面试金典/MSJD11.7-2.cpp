bool comp(const vector<int>& v1,const vector<int>& v2){
    return v1[0]>v2[0];
}
class Stack {
public:
    int getHeight(vector<vector<int> > actors, int n) {
        sort(actors.begin(),actors.end(),comp);
        vector<int> record(n);
        int result = 0;
        for(int i=0;i<n;++i){
            int temp = 1;
            for(int j=0;j<i;++j){
                if(actors[j][0]>actors[i][0]&&actors[j][1]>actors[i][1]){
                    temp = max(temp,record[j]+1);
                }
            }
            record[i] = temp;
            result = max(result,temp);
        }
        return result;
    }
};