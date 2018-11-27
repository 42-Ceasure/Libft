//

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	int				i;
	int				l;
	char			*s2;

	i = 0;
	l = ft_strlen(s1);
	if ((s2 = (char *)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
