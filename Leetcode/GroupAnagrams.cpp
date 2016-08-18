class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> record;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();++i){
            string key = strs[i];
            sort(key.begin(),key.end());
            record[key].push_back(i);
        }
        for(auto p : record){
            vector<string> group;
            for(auto i : p.second){
                group.push_back(strs[i]);
            }
            result.push_back(group);
        }
        return result;
    }
};