class Frequency {
private:
    map<string,int> record;
public:
    int getFrequency(vector<string> article, int n, string word) {
        if(record.find(word)!=record.end()){
            return record[word];
        }
        int  count = 0;
        for(auto s : article){
            if(s==word) ++count;
        }
        record[word] = count;
        return count;
    }
};