class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        vector<int> result(numbers.size());
        int i=0,j=numbers.size();
        while(i<numbers.size())
        {
        	int temp = numbers[i];
        	while(j<numbers.size()&&result[j]>temp)
        	{
        		numbers[i--]=result[j];
        		++j;
        	} 		
        	result[--j] = temp;
        	++i;
        }
        return result;
    }
};