
/*
*	说明：选择排序(升序)
*/

template<typename T>
void SelectSort(T arr[], size_t len)
{
	T tmp;
	size_t min = 0;
	for (size_t i = 0; i < len; i++)
	{
		min = i;
		for (size_t j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])	// 升序
			{
				min = j;
			}
		}

		if (min != i)	
		{
			tmp		= arr[min];
			arr[min]= arr[i];
			arr[i]	= tmp;
		}
	}
}