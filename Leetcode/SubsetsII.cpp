class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> result;
        result.push_back(vector<int>());
        int pre;
        for(int i=0;i<S.size();++i){
            if(i==0){
                result.push_back(vector<int>(1,S[i]));
            }else{
                int size = result.size();
                for(int j=0;j<size;++j){
                    if((pre==S[i]&&check(S,i,result[j]))||pre!=S[i]){
                        vector<int> temp = result[j];
                        temp.push_back(S[i]);
                        result.push_back(temp);
                    }
                }
            }
            pre = S[i];
        }
        return result;
    }
private:
    bool check(const vector<int> &S,const int index,const vector<int> &V){
        int count = 0;
        int i = index-1;
        while(i>=0&&S[i]==S[index]){
            --i;
            ++count;
        }
        for(int j=V.size()-1;j>=0;--j){
            if(V[j]==S[index]){
                --count;
            }
        }
        return count==0;
    }
};