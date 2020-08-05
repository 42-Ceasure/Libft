/**/

#include "libft.h"

int		ft_int_dsearch(int *tab, int min, int max, int val)
{
	int mid;

	if (max >= min)
	{
		mid = min + (max - min) / 2;
		if (tab[mid] == val)
			return (mid);
		if (tab[mid] > val)
			return (ft_int_dsearch(tab, min, mid - 1, val));
		return (ft_int_dsearch(tab, mid + 1, max, val));
	}
	return (-1);
}
