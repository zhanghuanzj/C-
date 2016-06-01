class Solution {
public:
    void push(int value) {
        s.push(value);
        if (minS.empty()||minS.top()>value)
        {
        	minS.push(value);
        }
        else
        {
        	minS.push(minS.top());
        }
    }
    void pop() {
    	if (!s.empty())
    	{
    		s.pop();
        	minS.pop();
    	}
    }
    int top() {
        return s.top();
    }
    int min() {
        return minS.top();
    }
private:
	stack<int> s;
	stack<int> minS;
};