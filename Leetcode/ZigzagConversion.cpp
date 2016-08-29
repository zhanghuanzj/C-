class Solution {
public:
    string convert(string s, int nRows){
        if(nRows == 1) return s;
        vector<string> result(nRows);
        int i = 0;
        while (i<s.size()){
            for (int j=0;j<nRows&&i<s.size();++j) {
                result[j] += s[i++];
            }
            for (int j=nRows-2;j>0&&i<s.size();--j) {
                result[j] += s[i++];
            }
        }
        string str;
        for (int i=0;i<nRows;++i) {
            str += result[i];
        }
        return str;
	}
};