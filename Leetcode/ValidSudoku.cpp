 
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> record(10,0);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    ++record[board[i][j]-'0'];
                    if(record[board[i][j]-'0']==2) return false;
                }
            }
            fill_n(record.begin(),10,0);
            for(int k=0;k<9;++k){
                if(board[k][i]!='.'){
                    ++record[board[k][i]-'0'];
                    if(record[board[k][i]-'0']==2) return false;
                }
            }
            fill_n(record.begin(),10,0);
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int k=0;k<9;++k){
                    if(board[i+k/3][j+k%3]!='.'){
                        ++record[board[i+k/3][j+k%3]-'0'];
                        if(record[board[i+k/3][j+k%3]-'0']==2) return false;
                    }
                }
                fill_n(record.begin(),10,0);
            }
        }
        return true;
    }
};