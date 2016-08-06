class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> record(ratings.size(),1);
        for(int i=1;i<ratings.size();++i){
            if(ratings[i]>ratings[i-1]){
                record[i] = record[i-1]+1;
            }
        }
        int result = record.back();
        for(int i=ratings.size()-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]&&record[i]<=record[i+1]){
                record[i] = record[i+1]+1;   
			}
            result += record[i];
        }
        return result;
    }
};