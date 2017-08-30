template<typename T>
long Partition(T arr[], long left, long right)
{
	long i = left, j = right;
	// ���λ��
	T flag = arr[i];

	while (i < j)
	{
		while (i < j && arr[j] >= flag) j--;
		if (i < j) arr[i++] = arr[j];

		while (i < j && arr[i] < flag) i++;
		if (i < j) arr[j--] = arr[i];
	}

	arr[i] = flag;
	return i;
}

/*
*	˵������������(β�ݹ��Ż�)
*/
template<typename T>
void QuickSort(T arr[], long left, long right)
{
	long index;
	while (left < right)
	{
		index = Partition(arr, left, right);
		QuickSort(arr, left, index - 1);
		left = index + 1;
	}
}

/*
*	˵������������(����)
*/
template<typename T>
void QuickSort2(T arr[], long left, long right)
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
	}
}