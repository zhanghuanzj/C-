bool IsPopOrder(vector<int> pushV,vector<int> popV) 
{
	 if (pushV.size()!=popV.size()||pushV.empty())
	 {
		 return false;
	 }
	 stack<int> s;
	 int index = 0;
	 for (auto v : pushV)
	 {
		 s.push(v);
		 while (!s.empty()&&index<popV.size()&&popV[index]==s.top())
		 {
			 s.pop();
			 ++index;
		 }
	 }
	 return s.empty()&&index==popV.size();
}
