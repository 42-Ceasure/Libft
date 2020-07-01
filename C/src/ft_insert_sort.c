/* ___ */

#include "libft.h"

void ft_insert_sort(int *tab, int size)
{
    int i;
    int j;
    int current;

    i = 1;
    while (i < size)
    {
        current = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > current)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = current;
        i++;
    }
}
