
/*
*	说明：计数排序(升序)
*	计数排序后的顺序为从小到大
*	arr[0...len-1]为待排数组，每个元素均是0-k中的一个值
*	crr[0...k]保存0...k中每个值在数组arr中出现的次数
*
*/
template<typename T>
void CountSort(T arr[], size_t len)
{
	size_t i, j = 0;

	T max, *crr;

	for (i = 0, max = arr[0]; i < len; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	crr = new T[max + 1];

	// 数组crr各元素置0
	memset(crr, 0, sizeof(T) * max);

	// 统计数组arr中每个元素重复出现的个数
	for (i = 0; i < len; i++)
	{
		crr[arr[i]]++;
	}

	// 根据crr[i]的大小，将元素i放入arr适当的位置
	for (T i = 0; i <= max; i++)
	{
		while ((crr[i]--) > 0)
		{
			arr[j++] = i;
		}
	}	

	delete[] crr;
	crr = NULL;
}