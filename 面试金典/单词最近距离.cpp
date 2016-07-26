class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {
        int distance = 2000;
        vector<int> wordx,wordy;
        for(int i=0;i<n;++i){
            if(article[i]==x) wordx.push_back(i);
            else if(article[i]==y) wordy.push_back(i);
        }
        int i = 0,j = 0;
        while(i<wordx.size()&&j<wordy.size()){
            distance = min(distance,abs(wordx[i]-wordy[j]));
            if(wordx[i]<wordy[j]){
                ++i;
            }
            else{
                ++j;
            }
        }
        return distance;
    }
};