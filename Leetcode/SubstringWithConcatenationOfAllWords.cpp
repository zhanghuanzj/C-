class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> index;
        map<string,int> record;
        for(auto word : words)
            record[word]++;
        int size = words.size(),len = words.front().size();
        for(int i=0;i<=(int)s.size()-size*len;++i){
            map<string,int> seen;
            int n = 0;
            while(n < size){
                string word = s.substr(i+n*len,len);
                seen[word]++;
                if(seen[word]>record[word])
                    break;
                ++n;
            }
            if(n==size) index.push_back(i);
        }
        return index;
    }
};