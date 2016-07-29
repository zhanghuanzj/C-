class AlphaMatrix {
public:
    int findAlphaMatrix(vector<string> dic, int n) {
        map<int,int> record;
        size_t result = 0;
        for(auto s : dic){
            record[s.size()]++;
            if(record[s.size()]>=s.size()){
                result = max(result,s.size()*s.size());
            }
        }
        return result;
    }
};