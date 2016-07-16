class Stack {
public:
    int getHeight(vector<int> men, int n) {
        vector<int> record(n);
        int result = 0;
        for(int i=0;i<n;++i){
            int temp = 1;
            for(int j=0;j<i;++j){
                if(men[j]<men[i])
                	temp = max(temp,record[j]+1);
            }
            record[i] = temp;
            result = max(temp,result);
        }
        return result;
    }
};