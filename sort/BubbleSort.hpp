
/*
*	ËµÃ÷£ºÃ°ÅİÅÅĞò(ÉıĞò)
*/
template<typename T>
void BubbleSort(T arr[], size_t len)
{
	T		tmp;
	bool	flag = true;

	for (size_t i = 0; i < len - 1 && flag; i++)
	{
		flag = false;
		for (size_t j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])	// ÉıĞòÅÅÁĞ
			{
				tmp			= arr[j];
				arr[j]		= arr[j + 1];
				arr[j + 1]	= tmp;
				flag		= true;
			}
		}
	}
}