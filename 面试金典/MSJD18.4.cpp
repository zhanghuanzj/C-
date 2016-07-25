class Count2 {
public:
    int countNumberOf2s(int n) {
        int factor = 1;
        int count = 0;
        while(n/factor){
            int left = n/(factor*10);
            int mid = (n/factor)%10;
            int right = n%factor;
            if(mid<2){
                count += left*factor;
            }
            else if(mid==2){
                count += left*factor + right+1;
            }
            else{
                count += (left+1)*factor;
            }
    		factor *= 10;
        }
        return count;
    }
};