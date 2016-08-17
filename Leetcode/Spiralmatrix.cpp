class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int y = matrix.size(),x = matrix.front().size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int num = 1,dir = 0;
        int px = 0,py = -1;
        int size =x*y;
        while(result.size()<size){
            if(dir&1){
                for(int i=0;i<y;++i){
                    px += dx[dir];
                    py += dy[dir];
                    result.push_back(matrix[px][py]);
                }
                --x;
            }else{
                for(int i=0;i<x;++i){
                    px += dx[dir];
                    py += dy[dir];
                    result.push_back(matrix[px][py]);
                }
                --y;
            }
            dir = (dir+1)%4;
        }
        return result;
    }  
};
