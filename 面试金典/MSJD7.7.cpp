class KthNumber {
public:
    int findKth(int k) {
        vector<int> v(k+1);
        int x=0,y=0,z=0;
        v[0] = 1;
        for(int j=1;j<=k;++j){
            v[j] = min(v[x]*3,min(v[y]*5,v[z]*7));
            while(v[x]*3<=v[j]) ++x;
            while(v[y]*5<=v[j]) ++y;
            while(v[z]*7<=v[j]) ++z;
        }
        return v.back();
    }
};