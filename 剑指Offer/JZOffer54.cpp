class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string==NULL||*string=='\0')
        {
        	return false;
        }
        if (*string=='+'||*string=='-')
        {
        	++string;
        }
        if (*string=='\0')
        {
        	return false;
        }
        int flag = scanDigital(&string);
    	if ((*string!='\0'&&*string!='.'&&*string!='e'&&*string!='E')||(!flag&&*string=='\0'))
    	{
    		return false;
    	}
    	if (*string=='.')
    	{
    		++string;
    		if (scanDigital(&string))
    		{
    			if (*string!='\0'&&*string!='e'&&*string!='E')
        		{
        			return false;
        		}
    		}
    	}
    	if (*string=='e'||*string=='E')
    	{
    		++string;
    		if (*string=='+'||*string=='-')
	        {
	        	++string;
	        }
    		if (!scanDigital(&string))
    		{
    			return false;
    		}
    	}
        return *string=='\0';
	}

    int scanDigital(char** string)
    {
    	int count = 0;
    	while(**string>='0'&&**string<='9')
    	{
    		++*string;
    		++count;
    	}
    	return count;	
    }

};