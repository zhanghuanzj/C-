template <typename T>
void heapModify(vector<T>& vec,int index,int size)
{
	while (index<size)
	{
		int lcIndex = index*2+1;
		if (lcIndex>=size)
		{
			break;
		}
		if (lcIndex+1<size&&vec[lcIndex+1]>vec[lcIndex])
		{
			lcIndex++;
		}
		if (vec[lcIndex]>vec[index])
		{
			swap(vec[lcIndex],vec[index]);
		}
		index = lcIndex;
	}
}

template <typename T>
void heapSort(vector<T>& vec)
{
	int index = vec.size()/2-1;
	while (index>=0)
	{
		heapModify(vec,index,vec.size());
		--index;
	}
	for (int i=vec.size()-1;i>0;--i)
	{
		swap(vec[i],vec[0]);
		heapModify(vec,0,i);
	}
}