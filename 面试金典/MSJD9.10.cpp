struct BoxT
{
	int w;
	int l;
	int h;
	BoxT(int x,int y,int z):w(x),l(y),h(z){}
	bool operator<(const BoxT& b)const
	{
		return w>b.w;
	}
};
class Box {
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
    	vector<BoxT> boxes;
        for(int i=0;i<n;++i)
        {
        	boxes.push_back(BoxT(w[i],l[i],h[i]));
        }
        stable_sort(boxes.begin(), boxes.end());
        vector<int> dp(n);
        int result = 0;
        for(int i=0;i<n;++i)
        {
        	int h = boxes[i].h;
        	for(int j=0;j<i;++j)
        	{
        		if (boxes[j].l>boxes[i].l)
        		{
        			h = max(h,dp[j]+boxes[i].h);
        		}
        	}
        	dp[i] = h;
            result = max(result,h);
        }
        return result;
    }
};