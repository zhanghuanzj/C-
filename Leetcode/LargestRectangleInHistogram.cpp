 class Solution {
 public:
	 int largestRectangleArea(vector<int> &height) {
		 stack<int> s;
		 int result = 0;
		 for (auto h : height)
		 {
			 int count = 1;
			 while (!s.empty() && s.top()>=h)
			 {
				 result = max(result,count*s.top());
				 s.pop();
				 ++count;
			 }
			 while (count--)
			 {
				 s.push(h);
			 }
			 result = max(result,count*h);
		 }
		 int count = 1;
		 while (!s.empty())
		 {
			 result = max(result,count*s.top());
			 s.pop();
             ++count;
		 }
		 return result;
	 }
 };