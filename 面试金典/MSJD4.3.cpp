class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        int size = vals.size();
        int height = 0;
        while(size)
        {
        	++height;
        	size = size>>1;
        }
        return height;
    }
};