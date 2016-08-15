class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> result;
        result.push_back(vector<int>());
        for(int i=0;i<S.size();++i){
            int size = result.size();
            for(int j=0;j<size;++j){
                vector<int> arr = result[j];
                arr.push_back(S[i]);
                result.push_back(arr);
            }
        }
        return result;
    }
};