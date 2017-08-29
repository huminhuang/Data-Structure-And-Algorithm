
/*
*	˵������������(����)
*	����������˳��Ϊ��С����
*	arr[0...len-1]Ϊ�������飬ÿ��Ԫ�ؾ���0-k�е�һ��ֵ
*	crr[0...k]����0...k��ÿ��ֵ������arr�г��ֵĴ���
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

	// ����crr��Ԫ����0
	memset(crr, 0, sizeof(T) * max);

	// ͳ������arr��ÿ��Ԫ���ظ����ֵĸ���
	for (i = 0; i < len; i++)
	{
		crr[arr[i]]++;
	}

	// ����crr[i]�Ĵ�С����Ԫ��i����arr�ʵ���λ��
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