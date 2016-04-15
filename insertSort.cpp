template <typename T>
void isort(vector<T> &vec)
{
	for (int j=1;j<vec.size();++j)
	{
		int i=j-1;
		T v = vec[j];
		while (i>=0&&v<vec[i])
		{
			vec[i+1]=vec[i];
			--i;
		} 
		vec[i+1]=v;
	}
}