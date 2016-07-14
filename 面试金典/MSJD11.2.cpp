bool com(const pair<string,string> &p1,const pair<string,string> &p2){
    return p1.second<p2.second;
}
class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {
        vector<pair<string,string>> strs;
        for(auto s:str){
            auto temp = s;
            sort(temp.begin(),temp.end());
            strs.push_back(make_pair(s,temp));
        }
        sort(strs.begin(),strs.end(),com);
        string key = strs.front().second;
        vector<string> result;
        result.push_back(strs.front().first);
        for(int i=1;i<strs.size();++i){
            if(key==strs[i].second && result.back()>strs[i].first){
                result.back() = strs[i].first;
            }
            else if(key!=strs[i].second){
                result.push_back(strs[i].first);
                key = strs[i].second;
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};