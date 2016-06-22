class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
    	vector<int> result;
        queue<pair<int,int>> dogs,cats;
        for(int i=0;i<ope.size();++i)
        {
        	if (ope[i][0]==1)
        	{
        		if (ope[i][1]>0)
        		{
        			dogs.push(make_pair(i,ope[i][1]));
        		}
        		else if (ope[i][1]<0)
        		{
        			cats.push(make_pair(i,ope[i][1]));
        		}
        	}
        	else if (ope[i][0]==2)
        	{

        		if (ope[i][1]==0)
        		{
        			if (!dogs.empty()&&!cats.empty())
	        		{
	        			if (dogs.front().first<cats.front().first)
	        			{
	        				result.push_back(dogs.front().second);
	        				dogs.pop();
	        			}
        				else
        				{
        					result.push_back(cats.front().second);
	        				cats.pop();
        				}
	        		}
	        		else if (!dogs.empty()&&cats.empty())
	        		{
	        			result.push_back(dogs.front().second);
	        			dogs.pop();
	        		}
	        		else if (!cats.empty()&&dogs.empty())
	        		{
	        			result.push_back(cats.front().second);
	        			cats.pop();
	        		}
        			
        		}
        		else if (ope[i][1]==1)
        		{
        			if (!dogs.empty())
	        		{
	        			result.push_back(dogs.front().second);
	        			dogs.pop();
	        		}
        		}
        		else if (ope[i][1]==-1)
        		{
        			if (!cats.empty())
	        		{
	        			result.push_back(cats.front().second);
	        			cats.pop();
	        		}
        		}
        	}
        }
        return result;
    }
};