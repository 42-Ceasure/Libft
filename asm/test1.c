#include "../asm/lib/libftasm.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define RESET	"\033[0m"
#define BOLD	"\033[1m"
//#define	UNBOLD	"\033[21m" /* UNBOLD not supported by zsh */
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define UNCOLOR	"\033[39m"
#define ULINE	"\033[4m"
#define UNULINE	"\033[24m"

/* Comment out to remove the NULL tests */
#define SEGFAULT_ME
/* If the test segfaults, try skipping the NULL tests */
/* to see if they are the ones giving you a hard time */

static void	set(char *color_code)
{
	printf("%s\n", color_code);
}

static void print_test_name(char *str)
{
	set(BLUE);
	set(BOLD);
	printf("%s\n", str);
	set(RESET);
	if (strlen(str) > 6)
		printf(":\t");
	else
		printf(":\t\t");
	fflush(stdout);
}

static void	print_test_results(int	return_value[], int control_value[], int n, int warning[])
{
	int		i, j;

	if (n)
	{
		i = 0;
		while (i < n)
		{
			printf("test %d", i);
			if (return_value[i] == control_value[i])
			{
				set(GREEN);
				printf(" OK");
				set(UNCOLOR);
				if (i != n - 1)
					printf(", ");
			}
			else
			{
				j = -1;
				if (warning)
				{
					j = 0;
					while (warning[j] != -1 && warning[j] != i)
						++j;
					if (warning[j] != i)
						j = -1;
				}
				if (j == -1)
				{
					set(RED);
					printf(" failed");
					set(UNCOLOR);
					printf(" [ctrl=%d, test=%d]", control_value[i], return_value[i]);
					if (i != n - 1)
						printf(", ");
				}
				else
				{
					set(YELLOW);
					printf(" disagreed");
					set(UNCOLOR);
					printf(" [ctrl=%d, test=%d]", control_value[i], return_value[i]);
					if (i != n - 1)
						printf(", ");
				}
			}
			++i;
		}
		printf("\n");
	}
	else
	{
		set(YELLOW);
		printf("no test was performed\n");
		set(UNCOLOR);
	}
}

static void	print_test_results_summary(int	return_value[], int control_value[], int n)
{
	int		i;

	if (n)
	{
		if (n == 1)
			printf("1 test ");
		else
			printf("%d tests ", n);
		i = 0;
		while (i < n && return_value[i] == control_value[i])
			++i;
		if (i == n && return_value[i - 1] == control_value[i - 1])
		{
			set(GREEN);
			printf("OK");
			set(UNCOLOR);
		}
		else
		{
			if (i == n)
				--i;
			set(RED);
			printf("failed");
			set(UNCOLOR);
			printf(" @ [i=%d, ctrl=%d, test=%d]", i, control_value[i], return_value[i]);
		}
		printf("\n");
	}
	else
	{
		set(YELLOW);
		printf("no test was performed\n");
		set(UNCOLOR);
	}
}

static void	f_iter(char *pc)
{
	++(*pc);
}

static void	f_iteri(unsigned int i, char *pc)
{
	*pc += i;
}

static char	f_map(char c)
{
	return (++c);
}

static char	f_mapi(unsigned int i, char c)
{
	return (c + i);
}

static void	f_del(void *ptr, size_t size)
{
	memset(ptr, 'a', size - 1);
}

static void	init(int tab[], int n, int c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = c;
		++i;
	}
}

static int	cmp(char *str1, char *str2)
{
	if (str1 && str2)
		return (strcmp(str1, str2));
	return (-42);
}

static int	ft_cmp(char *str1, char *str2)
{
	if (str1 && str2)
		return (ft_strcmp(str1, str2));
	return (-42);
}

static int	ncmp(char *str1, char *str2, size_t n)
{
	if (str1 && str2)
		return (strncmp(str1, str2, n));
	return (-42);
}

static int	tabcmp(char **tab1, char **tab2)
{
	if (tab1 && tab2)
	{
		while(*tab1 && *tab2)
		{
			if ((cmp(*(tab1++), *(tab2++))))
				return (1);
		}
		if (*tab1 != *tab2)
			return (-12);
		return (0);
	}
	return (-24);
}

static void	test_sign(int test[], int ctrl[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (test[i] * ctrl[i] > 0)
			test[i] = ctrl[i];
		++i;
	}
}

static void	test_negate(int ctrl[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ctrl[i] = !ctrl[i];
		++i;
	}
}

static void	free_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

static void	free_ctrl_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
	}
}

/*******************************************************************************/
/*                                                                             */
/*                            TEST FUNCTIONS                                   */
/*                                                                             */
/*******************************************************************************/

static void	test_bzero(void)
{
	int		test[2], ctrl[2];
	char	str1[]="test string",
			str2[]="test string",
			str3[]="one test string",
			str4[]="two test string";

	print_test_name("bzero");
	init(ctrl, 2, 0);
	init(test, 2, 0);
	bzero(str1, 0);
	ft_bzero(str2, 0);
	test[0] = cmp(str1, str2);
	bzero(str3, 10);
	ft_bzero(str4, 10);
	while (!(str3[ctrl[1]]))
		++(ctrl[1]);
	while (!(str4[test[1]]))
		++(test[1]);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_isalnum(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isalnum");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isalnum(i);
		test[i] = ft_isalnum(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isalpha(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isalpha");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isalpha(i);
		test[i] = ft_isalpha(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isascii(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isascii");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isascii(i);
		test[i] = ft_isascii(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isdigit(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isdigit");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isdigit(i);
		test[i] = ft_isdigit(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isprint(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isprint");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isprint(i);
		test[i] = ft_isprint(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_memalloc(void)
{
	int		test[2], ctrl[2];
	void	*ptr;

	print_test_name("memalloc");
	ctrl[0] = 512;
	if (!(ptr = ft_memalloc(ctrl[0])))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	test[0] = 0;
	while (test[0] < ctrl[0] && !(*((unsigned char*)ptr)))
		++(test[0]);
	free(ptr);
	ctrl[1] = 0;
	test[1] = 1;
	if (!(ptr = ft_memalloc(SIZE_MAX)))
		test[1] = 0;
	free(ptr);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_memcpy(void)
{
	int		test[5], ctrl[5], n;
	char	str1[]="test string", *str2, *str3;

	print_test_name("memcpy");
	init(ctrl, 5, 0);
	init(test, 5, 1);
	if (!(str2 = malloc(sizeof(*str2) * 20)) || !(str3 = malloc(sizeof(*str3) * 20)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	memset(str2, 'a', 20);
	memset(str3, 'a', 20);
	n = strlen(str1);
	test[0] = memcmp(memcpy(str2, str1, 0), ft_memcpy(str3, str1, 0), 20);
	test[1] = memcmp(memcpy(str2, str1, 1), ft_memcpy(str3, str1, 1), 20);
	test[2] = memcmp(memcpy(str2, str1, n), ft_memcpy(str3, str1, n), 20);
	test[3] = memcmp(memcpy(str2, str1, n + 1), ft_memcpy(str3, str1, n + 1), 20);
	str1[n - 1] = '\0';
	str1[n] = 'z';
	test[4] = memcmp(memcpy(str2, str1, n + 1), ft_memcpy(str3, str1, n + 1), 20);
	free(str2);
	free(str3);
	print_test_results(test, ctrl, 5, NULL);
}

static void	test_memset(void)
{
	int		test[4], ctrl[4];
	char	str1[]="don't kill me\n",
			str2[]="don't kill me\n";

	print_test_name("memset");
	init(ctrl, 4, 0);
	init(test, 4, 1);
	str1[3] = '\0';
	str2[3] = '\0';
	test[0] = memcmp(memset(str1, '-', 0), ft_memset(str2, '-', 0), 15);
	test[1] = memcmp(memset(str1, '-', 1), ft_memset(str2, '-', 1), 15);
	test[2] = memcmp(memset(str1, '-', 5), ft_memset(str2, '-', 5), 15);
	test[3] = memcmp(memset(str1, 0, 5), ft_memset(str2, 0, 5), 15);
	print_test_results(test, ctrl, 4, NULL);
}

static void	test_strcat(void)
{
	int		test[1], ctrl[1];
	char	*dst1, *dst2, src[]="test";

	print_test_name("strcat");
	if (!(dst1 = malloc(sizeof(*dst1) * (strlen(src) + 1) * 3)) || !(dst2 = malloc(sizeof(*dst2) * (strlen(src) + 1) * 3)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	ctrl[0] = 0;
	test[0] = cmp(strcat(dst1, src), ft_strcat(dst2, src));
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 1, NULL);
}

static void	test_strchr(void)
{
	int		test[3], ctrl[3];
	char	str[]="test string test string test string";

	print_test_name("strchr");
	init(ctrl, 3, 0);
	init(test, 3, 1);
	if (strchr(str, ' ') == ft_strchr(str, ' '))
		test[0] = 0;
	if (strchr(str, '\0') == ft_strchr(str, '\0'))
		test[1] = 0;
	if (strchr(str, '@') == ft_strchr(str, '@'))
		test[2] = 0;
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_strcmp(void)
{
	int		test[9], ctrl[9];

	/*                  /!\ strcmp and strncmp                               */
	/* ********************************************************************* */
	/* Only the sign of the values returned by strcmp and strncmp matters !! */
	/* ********************************************************************* */
	/* If you make your own tests or use them in your programs, depending on */
	/* the code written, gcc will sometimes make optimizations resulting in  */
	/* strcmp and strncmp returning -1, 0, or 1, instead of the exact        */
	/* difference between the values of the unsigned chars, as you've been   */
	/* led to expect. Your own ft_ versions won't do such a thing though and */
	/* you will get a false fail if you're not cautious.                     */
	
	/* This test takes only the sign into account. */
	print_test_name("strcmp");
	ctrl[0] = cmp("test string", "test string");
	ctrl[1] = cmp("test string", "test spring");
	ctrl[2] = cmp("test string", "test string ");
	ctrl[3] = cmp("test string ", "test string");
	ctrl[4] = cmp("", "test");
	ctrl[5] = cmp("test", "");
	ctrl[6] = cmp("", "");
	ctrl[7] = cmp("\200\230\100\255", "\200\230\100\255");
	ctrl[8] = cmp("\200\230\100\255", "\0\230\100\255");
	test[0] = ft_cmp("test string", "test string");
	test[1] = ft_cmp("test string", "test spring");
	test[2] = ft_cmp("test string", "test string ");
	test[3] = ft_cmp("test string ", "test string");
	test[4] = ft_cmp("", "test");
	test[5] = ft_cmp("test", "");
	test[6] = ft_cmp("", "");
	test[7] = ft_cmp("\200\230\100\255", "\200\230\100\255");
	test[8] = ft_cmp("\200\230\100\255", "\0\230\100\255");
	test_sign(test, ctrl, 9);
	print_test_results(test, ctrl, 9, NULL);
}

static void	test_strcpy(void)
{
	int		test[2], ctrl[2];
	char	*dst1, *dst2, src1[]="abababababababa", src2[]="cdcdcdcd";

	print_test_name("strcpy");
	init(ctrl, 2, 0);
	init(test, 2, 1);
	if (!(dst1 = malloc(strlen(src1) + 1)) || !(dst2 = malloc(strlen(src1) + 1)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	test[0] = cmp(strcpy(dst1, src1), ft_strcpy(dst2, src1));
	printf("\nvraie - %s\nmoi - %s\nsrc - %s\n", dst1, dst2, src1);
	ft_strcpy(dst1, src2);
	printf("\nmoi - %s\nsrc - %s\n\n", dst1, src2);
	ft_strcpy(dst1, src2);
	printf("\nmoi - %s\nsrc - %s\n\n", dst1, src2);
	if (!dst1[strlen(src2)])
		test[1] = 0;
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strdup(void)
{
	int		test[3], ctrl[3];
	char	*dst, src[]="test string";

	print_test_name("strdup");
	init(ctrl, 3, 0);
	init(test, 3, 1);
	dst = ft_strdup(src);
	test[0] = cmp(src, dst);
	if (!dst[strlen(src)])
		test[1] = 0;
	free(dst);
	dst = ft_strdup("");
	if (dst && !(*dst))
		test[2] = 0;
	free(dst);
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_strequ(void)
{
	int		test[12], ctrl[12], warning[]={9, -1};
	
	print_test_name("strequ");
#ifdef SEGFAULT_ME
	ctrl[9] = 0;
	ctrl[10] = 0;
	ctrl[11] = 0;
	test[9] = ft_strequ(NULL, NULL);
	test[10] = ft_strequ("test", NULL);
	test[11] = ft_strequ(NULL, "test");
#endif
	ctrl[0] = cmp("test string", "test string");
	ctrl[1] = cmp("test string", "test spring");
	ctrl[2] = cmp("test string", "test string ");
	ctrl[3] = cmp("test string ", "test string");
	ctrl[4] = cmp("", "test");
	ctrl[5] = cmp("test", "");
	ctrl[6] = cmp("", "");
	ctrl[7] = cmp("\200\230\100\255", "\200\230\100\255");
	ctrl[8] = cmp("\200\230\100\255", "\0\230\100\255");
	test[0] = ft_strequ("test string", "test string");
	test[1] = ft_strequ("test string", "test spring");
	test[2] = ft_strequ("test string", "test string ");
	test[3] = ft_strequ("test string ", "test string");
	test[4] = ft_strequ("", "test");
	test[5] = ft_strequ("test", "");
	test[6] = ft_strequ("", "");
	test[7] = ft_strequ("\200\230\100\255", "\200\230\100\255");
	test[8] = ft_strequ("\200\230\100\255", "\0\230\100\255");
	test_negate(ctrl, 9);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 12, warning);
#else
	print_test_results(test, ctrl, 9, warning);
#endif
}

static void	test_strlen(void)
{
	int		test[2], ctrl[2];

	print_test_name("strlen");
	test[0] = strlen("");
	ctrl[0] = ft_strlen("");
	test[1] = strlen("\001\002\003\004\005\200");
	ctrl[1] = ft_strlen("\001\002\003\004\005\200");
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strncpy(void)
{
	int		test[2], ctrl[2];
	size_t	n;
	char	*dst1, *dst2, src[]="test string";

	print_test_name("strncpy");
	init(ctrl, 2, 0);
	n = strlen(src) + 4;
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	memset(dst1, 'a', sizeof(*dst1) * n);
	memset(dst2, 'a', sizeof(*dst2) * n);
	dst1[n - 1] = '\0';
	dst2[n - 1] = '\0';
	test[0] = memcmp(strncpy(dst1, src, 3), ft_strncpy(dst2, src, n), 3);
	memset(dst1, 'a', sizeof(*dst1) * n);
	memset(dst2, 'a', sizeof(*dst2) * n);
	test[1] = memcmp(strncpy(dst1, src, n), ft_strncpy(dst2, src, n), n);
	
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strnew(void)
{
	int		test[3], ctrl[3], warning[]={2, -1};
	char	*str;

	print_test_name("strnew");
	init(ctrl, 3, 0);
	init(test, 3, 1);
#ifdef SEGFAULT_ME
	if (!(str = ft_strnew(SIZE_MAX)))
		test[2] = 0;
	free(str);
#endif
	ctrl[0] = 512;
	str = ft_strnew(ctrl[0]);
	test[0] = 0;
	while (test[0] < ctrl[0] && !(*str))
		++(test[0]);
	free(str);
	if (!(str = ft_strnew(SIZE_MAX - 1)))
		test[1] = 0;
	free(str);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 3, warning);
#else
	print_test_results(test, ctrl, 2, warning);
#endif
}

static void	test_tolower(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("tolower");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = tolower(i);
		test[i] = ft_tolower(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_toupper(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("toupper");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = toupper(i);
		test[i] = ft_toupper(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

int			main(void)
{
#ifdef SEGFAULT_ME
#else
#endif

	// test_bzero();
	// test_isalnum();
	// test_isalpha();
	// test_isascii();
	// test_isdigit();
	// test_isprint();
	// test_memalloc();
	// test_memset();
	// test_strcat();
	// test_strchr();
	// test_strcmp();
	test_strcpy();
	// test_strdup();
	// test_strequ();
	// test_strlen();
	// test_strncpy();
	// test_strnew();
	// test_tolower();
	// test_toupper();

	return (0);
}