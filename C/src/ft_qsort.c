/**/

#include "libft.h"

void ft_qsort(int *tab, int size)
{
	int i;
	int j;
	int tmp;
	int mid;

	i = 0;
	j = size;
	mid = tab[size / 2];
	while (i <= j)
	{
		while (tab[i] < mid)
			i++;
		while (tab[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < size)
		ft_qsort(tab + i, size - i);
	if (0 < j)
		ft_qsort(tab, j);
}
