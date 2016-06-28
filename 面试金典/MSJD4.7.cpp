class LCA {
public:
    int getLCA(int a, int b) {
        while(a!=b)
        {
        	if (a>b)
        	{
        		a = a>>1;
        	}
        	else 
        	{
        		b = b>>1;
        	}
        }
        return a;
    }
};