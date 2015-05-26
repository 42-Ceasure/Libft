/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:38:12 by acivita           #+#    #+#             */
/*   Updated: 2015/05/26 02:44:02 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm/lib/libftasm.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		test_isalpha(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isalpha(i) != isalpha(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isdigit(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isdigit(i) != isdigit(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isalnum(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isalnum(i) != isalnum(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isascii(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isascii(i) != isascii(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_isprint(void)
{
	int i=0;
	while (i < 200)
	{
		if (ft_isprint(i) != isprint(i))
			return (0);
		i++;
	}
	return (1);
}

int		test_strcmp(void)
{
	char str[4][8] = {"", " ", "Ah", "Coucou"};

	int i=0;
	int j;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(ft_strcmp(str[i],str[j]) != strcmp(str[i],str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int		test_strlen(void)
{
	char *str="Coucou";
	char *str2="";
	if (ft_strlen(str) != strlen(str))
		return (0);
	if (ft_strlen(str2) != strlen(str2))
		return (0);
	return (1);
}

int		test_strdup(void)
{
	if (strcmp(ft_strdup("yo"),strdup("yo")) != 0)
		return (0);
	return (1);
}

int		test_strcpy(void)
{
	char dest[10];
	char *src="Coucou";
	if (strcmp(ft_strcpy(dest,src), strcpy(dest,src)) != 0)
		return (0);
	return (1);
}

int		test_strncpy(void)
{
	char dest[10];
	char *src="Coucou";
	int i=0;
	if (strcmp(ft_strncpy(dest,src,i), strncpy(dest,src,i)) != 0)
		return (0);
	i = 5;
	if (strcmp(ft_strncpy(dest,src,i), strncpy(dest,src,i)) != 0)
		return (0);
	i = 10;
	if (strcmp(ft_strncpy(dest,src,i), strncpy(dest,src,i)) != 0)
		return (0);
	return (1);
}

int		test_strcat(void)
{
	char *s = "c est ";
	char *s1 = "moi";
	char *target = malloc(strlen(s) + strlen(s1) + 1);
	strcpy(target, s);

	if (strcmp(ft_strcat(target,s1), strcat(target,s1)) != 0)
		return (0);
	free(target);
	return (1);
}

int		test_strchr(void)
{
	char *s = "Mercure Venus Terre";
	char c = ' ';
	char z = 'z';
	if (strcmp(ft_strchr(s,c), strchr(s,c)) != 0)
		return (0);
	if ((ft_strchr(s,z) != NULL && strchr(s,c) != NULL))
		return (0);
	return (1);
}

int		test_memset(void)
{
	char *str=strdup("C M B   D T C");
	int i = 0;
	while (i < 2)
	{
	if(strcmp(ft_memset(str, '$', i), memset(str, '$', i)))
		return (0);
	i++;
	}
	return (1);
}
int		test_bzero(void)
{
	char *str=strdup("C M B   D T C");
	char *str2=strdup("C M B   D T C");
	int i = 0;
	while (i < 15)
	{
		ft_bzero(str,i);
		bzero(str2,i);
	if(memcmp(str, str2, i) != 0)
		return (0);
	i++;
	}
	return (1);
}

int		test_memcpy(void)
{
	char	*src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	dest[80];
	char	*ptr;
	char	*ptr2;
	char	*src2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	dest2[80];
	bzero(dest,80);
	bzero(dest2,80);
	ptr = (char *) memcpy(dest, src, 26);
	ptr2 = (char *) ft_memcpy(dest2, src2, 26);
	if (strcmp(ptr, ptr2) != 0)
		return (0);
	return (1);
}

int		test_tolower(void)
{
	int i;
	i = 0;
	while (i < 127)
	{
		if (tolower(i) != ft_tolower(i))
			return (0);
	i++;
	}
	return (1);
}

int		test_toupper(void)
{
	int i;
	i = 0;
	while (i < 127)
	{
		if (toupper(i) != ft_toupper(i))
			return (0);
	i++;
	}
	return (1);
}

int main (void)
{
	printf("\nFONCTION DE LA PREMIERE PAGE\n\n");
	printf("test ft_memset\t= %d\n", test_memset());
	printf("test ft_bzero\t= %d\n", test_bzero());
	printf("test ft_memcpy\t= %d\n", test_memcpy());
	printf("        ---\n");
	printf("test ft_strlen\t= %d\n", test_strlen());
	printf("test ft_strdup\t= %d\n", test_strdup());
	printf("test ft_strcpy\t= %d\n", test_strcpy());
	printf("test ft_strncpy\t= %d\n", test_strncpy());
	printf("test ft_strcat\t= %d\n", test_strcat());
	printf("test ft_strchr\t= %d\n", test_strchr());
	printf("test ft_strcmp\t= %d\n", test_strcmp());
	printf("        ---\n");
	printf("test ft_isalpha\t= %d\n", test_isalpha());
	printf("test ft_isdigit\t= %d\n", test_isdigit());
	printf("test ft_isalnum\t= %d\n", test_isalnum());
	printf("test ft_isascii\t= %d\n", test_isascii());
	printf("test ft_isprint\t= %d\n", test_isprint());
	printf("test ft_toupper\t= %d\n", test_toupper());
	printf("test ft_tolower\t= %d\n", test_tolower());
	if (ft_isupper(75) == 1)
		ft_puts("isupper y ok");
	if (ft_isupper(100) == 0)
		ft_puts("isupper n ok");	
	if (ft_islower(118) == 1)
		ft_puts("islower y ok");
	if (ft_islower(65) == 0)
		ft_puts("islower n ok");	
	ft_putchar('l');
	ft_putchar('\n');
	ft_putchar('p');
	ft_putchar('\n');
	ft_puts("loliloloulanoxification");
	return (0);
}
