class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        s1 = s1+s1;
        if (s1.find(s2)==-1)
        {
        	return false;
        }
        return true;
    }
};