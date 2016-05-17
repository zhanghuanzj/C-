class Solution {
public:
    bool match(char* str, char* pattern)
    {
    	if (str==NULL||pattern==NULL)
    	{
    		return false;
    	}
        if(*str=='\0'&&*pattern=='\0')
        {
            return true;
        }
    	if ( *str!='\0'&&*pattern=='\0')
    	{
    		return false;
    	}
    	if (*(pattern+1)=='*')
    	{
    		if (*str==*pattern||(*pattern=='.'&&*str!='\0'))
    		{
    			return match(str+1,pattern+2)||match(str,pattern+2)||match(str+1,pattern);
    		}
    		else
    		{
    			return match(str,pattern+2);
    		}
    	}
    	if (*str==*pattern||(*pattern=='.'&&*str!='\0'))
    	{
    		return match(str+1,pattern+1);
    	}
    	return false;
    }
};