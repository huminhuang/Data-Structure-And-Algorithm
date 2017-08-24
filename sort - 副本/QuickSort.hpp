/*
*	说明：快速排序(升序)
*/

template<typename T>
void QuickSort(T arr[], long left, long right)
{
	if (left < right)
	{
		long i = left, j = right;
		T x = arr[left];
		while (i < j)
		{
			while (i < j && arr[j] >= x){
				j--;
			}
			if (i < j){
				arr[i++] = arr[j];
			}

			while (i < j && arr[i] < x){
				i++;
			}
			if (i < j){
				arr[j--] = arr[i];
			}
		}
		arr[i] = x;
		QuickSort(arr, left, i - 1);
		QuickSort(arr, i + 1, right);

		if (i >= right)
		{
			int mm = 0;
			mm++;
		}
	}
}