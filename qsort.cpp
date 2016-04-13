template <typename T>
void qsort(vector<T> &vec,int left,int right)
{
	if (left>=right||vec.size()<=1)
	{
		return;
	}
	T v = vec[left];
	int i = left;
	for (int j=i+1;j<=right;++j)
	{
		if (vec[j]<v)
		{
			swap(vec[++i],vec[j]);
		}
	}
	swap(vec[left],vec[i]);
	qsort(vec,left,i-1);
	qsort(vec,i+1,right);
}