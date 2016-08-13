class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(pow(2,n));
        for (int i=1;i<=n;++i)
        {
            int size = 1<<i;
            int flag = 1<<(i-1);
            int index = 0;
            for (int j=size-1;2*j>=size;--j)
            {
                result[j] = result[index++]|flag;  //左部插入1
            }
        }
        return result;
    }
};