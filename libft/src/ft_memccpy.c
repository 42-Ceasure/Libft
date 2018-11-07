//

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void			*str;

	str = ft_memchr(src, c, n);
	if (str != NULL)
		return (ft_memcpy(dst, src, str - src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}