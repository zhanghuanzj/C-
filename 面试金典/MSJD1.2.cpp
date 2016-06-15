class Reverse {
public:
    string reverseString(string iniString) {
        int left = 0;
        int right = iniString.size()-1;
        while(left<right)
        {
        	swap(iniString[left++],iniString[right--]);      
        }
        return iniString;
    }
};