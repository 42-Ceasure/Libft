/**/

#include "libft.h"

int		ft_int_dsearch(int *tab, size_t size, int val)
{
	int min;
	int max;
	int mid;

	min = 0;
	max = size - 1;
	while (min <= max)
	{
		mid = min + (max - min) / 2;
		if (tab[mid] == val)
			return (val);
		if (tab[mid] < val)
			min = mid + 1;
		else
			max = mid - 1;
	}
	return (-1);
}
